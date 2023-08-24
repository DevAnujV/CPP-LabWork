#include <iostream>
#include <fstream>
#include <algorithm>
#include <cctype>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iterator>
#include"CrimeStatistics.h"
using namespace std;
namespace sdds {
	CrimeStatistics::CrimeStatistics(const char* filename)
	{
		if (!filename) {
			throw std::string("File does not exist!");
		}
		else {
			ifstream file(filename);
			if (file.is_open()) {
				do {
					Crime tempObj;
					size_t counter = 25;
					size_t i = 0;
					string tempCrimeDataStore{};
					getline(file, tempCrimeDataStore);
					tempObj.s_province = tempCrimeDataStore.substr(i, counter);
					tempObj.s_province.erase(tempObj.s_province.begin(), find_if(tempObj.s_province.begin(), tempObj.s_province.end(), bind1st(not_equal_to<char>(), ' ')));
					tempObj.s_province.erase(std::find_if(tempObj.s_province.rbegin(), tempObj.s_province.rend(), bind1st(not_equal_to<char>(), ' ')).base(), tempObj.s_province.end());
					i = counter;

					tempObj.s_district = tempCrimeDataStore.substr(i, 25);
					//init += 25;

					tempObj.s_district.erase(tempObj.s_district.begin(), find_if(tempObj.s_district.begin(), tempObj.s_district.end(), bind1st(not_equal_to<char>(), ' ')));
					tempObj.s_district.erase(std::find_if(tempObj.s_district.rbegin(), tempObj.s_district.rend(), bind1st(not_equal_to<char>(), ' ')).base(), tempObj.s_district.end());
					i += 25;

					tempObj.s_crime = tempCrimeDataStore.substr(i, 25);
					//init += 25;
					tempObj.s_crime.erase(tempObj.s_crime.begin(), find_if(tempObj.s_crime.begin(), tempObj.s_crime.end(), bind1st(not_equal_to<char>(), ' ')));
					tempObj.s_crime.erase(std::find_if(tempObj.s_crime.rbegin(), tempObj.s_crime.rend(), bind1st(not_equal_to<char>(), ' ')).base(), tempObj.s_crime.end());
					i += 25;

					tempObj.s_year = stoi(tempCrimeDataStore.substr(i, 5));
					i += 5;

					tempObj.s_numCrimeCases = stoi(tempCrimeDataStore.substr(i, 5));
					i += 5;

					tempObj.m_resolved = stoi(tempCrimeDataStore.substr(i, 5));
					this->CrimeCollection.push_back(tempObj);



				} while (!file.eof());
			}
		}
	}

	void CrimeStatistics::sort(const std::string& fieldName)
	{
		std::sort(CrimeCollection.begin(), CrimeCollection.end(), [&](const Crime& c1, const Crime& c2) {
			if (fieldName == "Province") {
				return c1.s_province < c2.s_province;
			}
			else if (fieldName == "Crime") {
				return c1.s_crime < c2.s_crime;
			}
			else if (fieldName == "Cases") {
				return c1.s_numCrimeCases < c2.s_numCrimeCases;
			}
			else {
				return c1.m_resolved < c2.m_resolved;
			}

			});
	}
	void CrimeStatistics::cleanList()
	{
		std::transform(CrimeCollection.begin(), CrimeCollection.end(), CrimeCollection.begin(), [](Crime& c) {
			if (c.s_crime == "[None]") {
				c.s_crime.clear();
			}
			return c;
			});

	}
	bool CrimeStatistics::inCollection(const std::string& crimeName) const
	{
		return std::any_of(CrimeCollection.begin(), CrimeCollection.end(), [&](const Crime& c) {
			return (c.s_crime == crimeName);
			});
	}

	std::list<Crime> CrimeStatistics::getListForProvince(const std::string provinceName) const
	{
		std::list<Crime> tempList;
		copy_if(CrimeCollection.begin(), CrimeCollection.end(), std::back_inserter(tempList), [&](const Crime& c) {
			if (provinceName == c.s_province) {
				return true;
			}
			return false;
			});
		return tempList;
	}

	void CrimeStatistics::display(std::ostream& out) const
	{
		int totalCases{};
		int totalResolvedCases{};

		for_each(CrimeCollection.begin(), CrimeCollection.end(), [&](auto& x) {

			totalCases += x.s_numCrimeCases;
			totalResolvedCases += x.m_resolved;
			out << x;
			out << endl;
			});
		out << setw(89) << setfill('-') << '\n' << setfill(' ');
		out << "| " << setw(78) << " Total Crimes: " << setw(6) << totalCases << " |\n";
		out << "| " << setw(78) << " Total Resolved Cases: " << setw(6) << totalResolvedCases << " |\n";
	}

	ostream& operator<<(ostream& out, const Crime& theCrime) {
		out << "| " << setfill(' ') << left << setw(21) << theCrime.s_province << " | " << left << setw(15) << theCrime.s_district << " | " << left << setw(20) << theCrime.s_crime
			<< " | " << right << setw(6) << theCrime.s_year << " | " << right << setw(4) << theCrime.s_numCrimeCases << " | " << setw(3) << theCrime.m_resolved << " |";
		return out;
	}

}