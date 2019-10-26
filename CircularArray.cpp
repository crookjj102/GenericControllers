#include "CircularArray.h"
#include <cstdlib>
#include <algorithm>

namespace filters{
	CircularArray::CircularArray(unsigned int capacity)
	{
		// starting out with a set size
		index = 0;
		this->capacity = capacity;
		values = (float*) calloc(capacity, sizeof(float));
	}

	CircularArray::CircularArray()
	{
		// starting out with no memory
		index = 0;
		this->capacity = 0;
		values = 0;
	}
	
	CircularArray::~CircularArray()
	{
		// deallocate memory 
		free(values);
	}

	void CircularArray::allocate(int capacity)
	{
		// allocate new memory
		float *p = (float*) calloc(capacity, sizeof(float));
		
		// copy old memory to new memory
		std::copy(values, values + this->capacity, p);

		// deallocate the old memory
		free(values);

		// remember new memory
		values = p;
		this->capacity = capacity;
	}
	
	float& CircularArray::next()
	{
		// compute index of next element
		index = (index + 1) % capacity;

		// return a reference to the value
		return values[capacity];
	}

	float& CircularArray::previous()
	{
		// compute index of previous element
		index = (index - 1) >= 0 ? (index - 1) : capacity - 1;

		// return a reference to the value
		return values[index];
	}

	float& CircularArray::operator[](int idx)
	{
		// compute index from relative idx
		int tempIndex = (index + idx) % capacity;
		tempIndex >= 0 ? tempIndex : capacity + tempIndex;
		
		// return a reference to the value
		return values[ tempIndex ];
	}
}
