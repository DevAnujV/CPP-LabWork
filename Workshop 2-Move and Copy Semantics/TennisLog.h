/*
* Name - Anuj Verma
* Seneca Email - averma100@myseneca.ca
* Seneca Student ID - 180483216
* Date of completion - 2023/05/28
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#ifndef _SDDS_TENNISLOG_H
#define _SDDS_TENNISLOG_H

#include <string>

namespace sdds {

   typedef struct X{
      std::string tm_tournamentID{};
      std::string tm_tournamentName{};
      unsigned tm_matchID{};
      std::string tm_winnerOfMatch;
      std::string tm_loserOfMatch;
   } TennisMatch;
   
   std::ostream& operator<<(std::ostream& os, const TennisMatch& tm);
   std::ostream& lORr(std::ostream& os,const char lORr);


   class TennisLog {

      TennisMatch* dynArray{};
      int numberOfMatches = 0; // self made to keep the track of matches

   public:
      TennisLog() = default;
      TennisLog(const char* fileName);
      TennisLog(const TennisLog& x);
      TennisLog& operator=(const TennisLog& x);
      // move constructor and move assignment
      TennisLog(TennisLog&& x);
      TennisLog& operator=(TennisLog&& x);
      void addMatch(const TennisMatch& newMatch);
      TennisLog findMatches(const char* nameOfPlayer)const;
      TennisMatch operator[](const size_t &x);
      operator size_t();
      ~TennisLog();

   };

}

#endif // !1
