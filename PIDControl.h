#ifndef PIDControl_h
#define PIDControl_h
/*
This is a basic 1-dimensional PID controller.
*/
class PIDControl
{
public:
	void setGains(float P, float I, float D);//changes the gains
	void setPoint(float setpoint);//changes the setpoint
	void setLimits(float lowerLimit, float upperLimit);//makes sure that the outputs don't exceed the specified min/max.
	void setMaxDerivative(float maxDer);//sets the maximum value that the derivative is allowed.
	void setMinimumAbsOutputValue(float minOutValue);// motors have a minimum voltage that will move them.
	void setMaximumAbsOutputValue(float MaxOutValue);
	float getoutput(sensorValue);//returns the output
private:
	float _derivative(float err1, float err2, float time1, float time2);
	float _integral(float err1, float err2, float time1, float time2);
	float _setpoint = 1.00;
	float _kp = 1.00; //default proportional gain
	float _ki = 1.00; //default integral gain
	float _kd = 1.00; //default derivative gain
	float _LL = -1000; //default lower limit of output
	float _UL = 1000; //default upper limit of output
	float _maxDerivative = 1000; //prevents excessive controller output due to error. will need to replace with filters.
	float _maxIntegral = 1000; //prevents startup integral from dominating the response.
	float _absMinOut = 1;//default minimum motor value to move.
	float _absMaxOutput = 1000;//default saturation value.
	float _ensureValidOutput(float intendedOutput);//checks to ensure that we're not sending nonsense.
	float _getError(float sensorValue);
	float _prevErr = 0;
	float _prevTime = 0;
}