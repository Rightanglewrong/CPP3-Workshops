#ifndef SDDS_UNIQUEQUEUE_H
#define SDDS_UNIQUEQUEUE_H
#include <iostream>
#include <cmath>
#include "Queue.h"

namespace sdds {

	template<typename T>
	class UniqueQueue : public Queue<T, 100> {
	public:
		bool push(const T& item) {
			for (unsigned int i = 0; i < 100; i++)
			{
				if (item == this->operator[](i))
				{
					return false;
				}
			}
			return Queue<T, 100>::push(item);
		}
	};

	//speciallize
	template<>
	bool UniqueQueue<double>::push(const double& item) {
		for (unsigned int i = 0; i < 100; i++)
		{
			if (item == this->operator[](i))
			{
				return false;
			}
			else
			{
				double diff = std::fabs(item - this->operator[](i));
				if (diff <= 0.005) 
				{
					return false;
				}
			}
		}
		return Queue<double, 100>::push(item);
	}
}

#endif