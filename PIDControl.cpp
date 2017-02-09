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

void setLimits(float lowerLimit, float upperLimit)
{
	_LL = lowerLimit;
	_UL = upperLimit;
}
void setMaxDerivative(float maxDer)
{
	_maxDerivative = maxDer;
}
void setMinimumAbsMotorValue(float minOutputValue)
{
	_absMinOut = minOutputValue;
}
float getoutput(sensorValue)
{

}