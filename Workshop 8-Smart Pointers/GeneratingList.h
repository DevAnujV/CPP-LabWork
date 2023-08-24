#ifndef SDDS_GENERATINGLIST_H
#define SDDS_GENERATINGLIST_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <memory>
#include <utility>
#include <fstream>

namespace sdds {
	template<typename T>
	class GeneratingList {

		std::vector<T> list;
	public:

		GeneratingList(){}
		GeneratingList(const char* f) {
			std::ifstream file(f);
			if (!file)
				throw std::string("*** Failed to open file ") + std::string(f) + std::string(" ***");

			while (file) {
				T t;
				if (t.load(file))
					list.push_back(T(t));
			}
		}

		size_t size() const { return list.size(); }
		const T& operator[](size_t i) const { return list[i]; }

		//TODO: Implement the Luhn Algorithm to check the 
		//      valadity of SIN No's
		bool isLuhnValid(const std::string& number)const {
			int sum = 0;
			bool alternate = false;

			for (int i = number.length() - 1; i >= 0; --i) {
				int digit = number[i] - '0';

				if (alternate) {
					digit *= 2;
					if (digit > 9) {
						digit -= 9;
					}
				}

				sum += digit;
				alternate = !alternate;
			}

			return sum % 10 == 0;
		}
		

		//TODO: Overload the += operator with a smart pointer
		// as a second operand.
		void operator+=(std::unique_ptr<T> sPtr) {
			list.push_back(*sPtr);
		}
		

		void operator+=(T* t) {
			list.push_back(*t); // Your function receives the address of an object to be stored in the GeneratingList container and moves the object into that container.
			// CHeck aithe const aana k nahi   !!!!!!!!!!!!!!!!!!!!
		}

		
		void print(std::ostream& os) const {
			os << std::fixed << std::setprecision(2);
			for (auto& e : list)
				e.print(os);
		}
	};

	template<typename T>
	std::ostream& operator<<(std::ostream& os, const GeneratingList<T>& rd) {
		rd.print(os);
		return os;
	}
}
#endif // !SDDS_GENERATINGLIST_H
