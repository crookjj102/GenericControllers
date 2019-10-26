#include "CircularArray.h"

#ifndef _AVERAGINGFILTER_
#define _AVERAGINGFILTER_
namespace filters{
	class MovingAverager{
		public:
			// Constructor and destructor
			MovingAverager(int tapCount);
			~MovingAverager();

			// return new moving average
			float push(float value);
			float runningAverage();
		private:
			float average;
			int tapCount;
			
			// circular array helpers
			CircularArray values;
	};
}
#endif
