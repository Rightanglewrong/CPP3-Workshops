/*
Workshop 8 Part 1
Name: Benny Yang
Student ID: 112654223
Email: byang68@myseneca.ca
Date: July 14th, 2023
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*/
#include "EmpProfile.h"
#include "GeneratingList.h"
#include "WritingRecord.h"

using namespace std;

namespace sdds
{
	GeneratingList<EmployeeWage> writeRaw(const GeneratingList<Employee> &emp, const GeneratingList<Salary> &sal)
	{
		GeneratingList<EmployeeWage> activeEmp;

		// TODO: Add your code here to build a list of employees
		//         using raw pointers
		for (size_t i = 0; i < emp.size(); i++)
		{
			for (size_t j = 0; j < sal.size(); j++)
			{
				if (emp[i].id == sal[j].id)
				{
					if (!activeEmp.isValidSin(emp[i].id))
					{
						std::string err = "*** Invalid Employee ID";
						throw err;
					}
					auto *empWage = new EmployeeWage(emp[i].name, sal[j].salary);
					try
					{
						empWage->rangeValidator();
					}
					catch (const std::string err)
					{
						delete empWage;
						throw err;
					}
					activeEmp += empWage;
					delete empWage;
				}
			}
		}
		return activeEmp;
	}
}