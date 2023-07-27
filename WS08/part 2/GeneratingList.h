/*
Workshop 8 Part 2
Name: Benny Yang
Student ID: 112654223
Email: byang68@myseneca.ca
Date: July 21th, 2023
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_GENERATINGLIST_H
#define SDDS_GENERATINGLIST_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <memory>
#include <utility>
#include <fstream>

namespace sdds
{
	template <typename T>
	class GeneratingList
	{

		std::vector<T> list;

	public:
		GeneratingList() {}
		GeneratingList(const char *f)
		{
			std::ifstream file(f);
			if (!file)
				throw std::string("*** Failed to open file ") + std::string(f) + std::string(" ***");

			while (file)
			{
				T t;
				if (t.load(file))
					list.push_back(T(t));
			}
		}

		size_t size() const { return list.size(); }
		const T &operator[](size_t i) const { return list[i]; }

		// TODO: Implement the Luhn Algorithm to check the
		//       valadity of SIN No's
		bool isValidSin(const std::string sin) const
		{
			int temp = std::stoi(sin);
			int digit = 0;
			bool secondDigits = false;
			int sum = 0;

			while (temp > 0)
			{
				digit = temp % 10;
				if (secondDigits)
				{
					digit *= 2;
					if (digit > 9)
					{
						digit -= 9;
					}
				}
				sum += digit;
				temp /= 10;
				secondDigits = !secondDigits;
			}
			return (sum % 10 == 0);
		}

		// TODO: Overload the += operator with a smart pointer
		//  as a second operand.
		void operator+=(const std::unique_ptr<T> &obj)
		{
			if (obj != nullptr)
			{
				list.push_back(*obj);
			}
		}

		// TODO: Overload the += operator with a raw pointer
		//  as a second operand.
		void operator+=(const T *obj)
		{
			if (obj != nullptr)
			{
				list.push_back(*obj);
			}
		}

		void print(std::ostream &os) const
		{
			os << std::fixed << std::setprecision(2);
			for (auto &e : list)
				e.print(os);
		}
	};

	template <typename T>
	std::ostream &operator<<(std::ostream &os, const GeneratingList<T> &rd)
	{
		rd.print(os);
		return os;
	}
}
#endif // !SDDS_GENERATINGLIST_H
