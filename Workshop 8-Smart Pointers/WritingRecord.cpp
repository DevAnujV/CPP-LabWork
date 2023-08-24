#include "GeneratingList.h"
#include "EmpProfile.h"
#include "WritingRecord.h"

using namespace std;

namespace sdds {
	GeneratingList<EmployeeWage> writeRaw(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal) {
		GeneratingList<EmployeeWage> activeEmp;

		for (size_t i = 0; i < emp.size(); ++i) {
			for (size_t j = 0; j < sal.size(); j++) {
				if (emp[i].id == sal[j].id) {

					EmployeeWage* eWObj = new EmployeeWage(emp[i].name, sal[j].salary);

					try {
						// push active employee in the activeEmp list only if it pass the below 2 validations
						eWObj->rangeValidator(); // validation 1


						if (sal.isLuhnValid(emp[i].id)) { // validation 2
							// pass

							activeEmp.operator+=(eWObj);
							delete eWObj;
						}
						else {
							throw;
						}

					}
					catch (...) {
						//cout << "Emp cannot be added. Salary is " << sal[j].salary;
						delete eWObj;
						throw std::string("*** Employees salaray range is not valid");
					}
				}
			}
		}

		return activeEmp;
	}
	GeneratingList<EmployeeWage> writeSmart(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal) {
		GeneratingList<EmployeeWage> activeEmp;


		for (size_t i = 0; i < emp.size(); ++i) {
			for (size_t j = 0; j < sal.size(); j++) {
				if (emp[i].id == sal[j].id) {
				
					unique_ptr<EmployeeWage> eWObj(new EmployeeWage(emp[i].name, sal[j].salary));
					
					try {
						// push active employee in the activeEmp list only if it pass the below 2 validations
						eWObj->rangeValidator(); // validation 1


						if (sal.isLuhnValid(emp[i].id)) { // validation 2
							// pass

							activeEmp.operator+=(move(eWObj));
						}
						else {
							throw;
						}

					}
					catch (...) {						
						throw std::string("*** Employees salaray range is not valid");
					}
				}
			}
		}

		return activeEmp;
	}
}