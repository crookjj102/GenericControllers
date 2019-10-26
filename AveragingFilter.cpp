#include "AveragingFilter.h"

namespace filters
{
	// --- Moving Averager filter ---
	MovingAverager::MovingAverager(int tapCount)
	{
		// remember how many taps, will be important for averaging
		this->tapCount = tapCount;

		// create a new appropriately sized circular array
		values.allocate(tapCount);
	}

	MovingAverager::~MovingAverager() { }

	float MovingAverager::push(float value)
	{
		// subtract the farthest back value
		average -= values[1];
		
		// add in new value
		values[1] = value / tapCount;

		// incorporate into the running average
		average += values[0];

		// return the average
		return average;
	}

	float MovingAverager::runningAverage()
	{
		return average;
	}
}
