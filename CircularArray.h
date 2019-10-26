#include <cstdlib>

#ifndef _CIRCULARARRAY_
#define _CIRCULARARRAY_

namespace filters{
	class CircularArray{
		public:
			CircularArray(unsigned int capacity);
			CircularArray();
			~CircularArray();

			float& next();
			float& previous();
			float& operator[](int);
			void allocate(int capacity);
		private:
			float* values;
			int capacity;
			unsigned int index;
	};
}
#endif
