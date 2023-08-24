#ifndef _SDDS_CRIMESTATISTICS_H
#define _SDDS_CRIMESTATISTICS_H
#include <vector>
#include<string>
#include<list>
namespace sdds {
	struct Crime {
		std::string s_province{};
		std::string s_district{};
		std::string s_crime{};
		int s_numCrimeCases{};
		int m_resolved{};
		int s_year{};
	};

	class CrimeStatistics {
		std::vector<Crime> CrimeCollection;
	public:
		CrimeStatistics(const char* filename);
		void display(std::ostream& out) const;
		void sort(const std::string& fieldName);
		void cleanList();
		bool inCollection(const std::string& crimeName) const;
		std::list<Crime> getListForProvince(const std::string provinceName) const;
	};
	std::ostream& operator<<(std::ostream& out, const Crime& theCrime);
}

#endif