#ifndef SDDS_QUEUE_H
#define SDDS_QUEUE_H
#include <iostream>
#include <cstring>
#include "Dictionary.h"

namespace sdds {

	template<typename T, unsigned int CAPACITY>
	class Queue {
		T m_element[CAPACITY]{};
		unsigned int m_stored{};
		static T dummy;

	public:
		Queue() {};
		virtual ~Queue() {};
		virtual bool push(const T& item) {
			bool added = false;
			if (m_stored < CAPACITY)
			{
				m_element[m_stored] = item;
				m_stored++;
				added = true;
			}
			return added;
		}

		T pop() {
			T temp{};
			if (m_stored > 0)
			{
				temp = m_element[0];
				for (unsigned int i = 0; i < m_stored; i++)
				{
					m_element[i] = m_element[i + 1];
				}
				m_stored--;
			}
			return temp;
		}                       

		unsigned int size() const { return m_stored; } 
		
		void display(std::ostream& os = std::cout) const {
			os << "----------------------" << std::endl;
			os << "| Dictionary Content |" << std::endl;
			os << "----------------------" << std::endl;
			for (unsigned int i = 0; i < m_stored; i++)
			{
				if (m_element != 0)
				{
					os << m_element[i] << std::endl;
				}
				else
				{
					os << dummy << std::endl;
				}
			}
			os << "----------------------" << std::endl;
		}
		
		T operator[](unsigned int index) const { 
			if (index < m_stored)
			{
				return m_element[index];
			}
			else
			{
				return dummy;
			}
		}
	};

	//specialize
	template<>
	Dictionary Queue<Dictionary, 100u>::dummy = { "Empty Term", "Empty Substitute" };

	//defining for dummy
	template<typename T, unsigned int CAPACITY>
	T Queue<T, CAPACITY>::dummy{};
}

#endif