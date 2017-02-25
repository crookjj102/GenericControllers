#include "PIDControl.h"

void PIDControl::setGains(float P, float I, float D)
{
	_kp = P;
	_ki = I;
	_kd = D;
}

void PIDControl::setPoint(float setpoint)
{
	_setpoint = setpoint;
}

void PIDControl::setLimits(float lowerLimit, float upperLimit)
{
	_LL = lowerLimit;
	_UL = upperLimit;
}
void PIDControl::setMaxDerivative(float maxDer)
{
	//should we do this statistically?
	_maxDerivative = maxDer;
}
void PIDControl::setMinimumAbsOutputValue(float minOutputValue)
{
	_absMinOut = minOutputValue;
}
void PIDControl::setMaximumAbsOutputValue(float maxOutputValue)
{
	_absMaxOutput = maxOutputValue;
}

float PIDControl::getError(float sensorValue)
{
	return sensorValue - _setpoint;
}

float PIDControl::derivative(float err1, float err2, float time1, float time2)
{
	float der = (err2 - err1) / (time2 - time1);
	if (abs(der) < _maxDerivative)
	{
		//if this value makes sense
		return der;
	}
	else
	{
		//this value is probably noise. Don't affect output change.
		return 0;
	}
}
float PIDControl::integral(float err1, float err2, float time1, float time2)
{
	float sum = (err2 - err1) * (time2 - time1);
	//allow for the starting error
	if (abs(sum) > _maxIntegral)
	{
		return 0;
	}
	else //value is ok.
	{

		return sum;
	}
}

float PIDControl::_ensureValidOutput(float intendedOutput)
{
	if (intendedOutput > _absMaxOutput)
	{
		return _absMaxOutput;
	}
	else if (intendedOutput < -_absMaxOutput)
	{
		return -_absMaxOutput;
	}
	else if (abs(intendedOutput) < _absMinOut)
	{
		if (intendedOutput > 0)
		{
			return _absMinOut;
		}
		else
		{
			return -_absMinOut;
		}
	}
	else
	{

		return intendedOutput;
	}
}

float PIDControl::getoutput(sensorValue, timeStamp)
{
	float currErr = getErr(sensorValue);
	float out = _kp * currErr + _ki * integral(_prevErr, currErr, _prevTime, timeStamp) + kd * derivative(_prevErr, currErr, _prevErr, timeStamp);
	_prevErr = currErr;
	_prevTime = timeStamp;
	return _ensureValidOuotput(out);
}