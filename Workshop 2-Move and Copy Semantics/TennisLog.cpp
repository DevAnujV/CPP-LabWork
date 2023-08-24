/*
* Name - Anuj Verma
* Seneca Email - averma100@myseneca.ca
* Seneca Student ID - 180483216
* Date of completion - 2023/05/28
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#include <iostream>
#include <fstream>
#include "TennisLog.h"

using namespace std;

namespace sdds {

   std::ostream& operator<<(std::ostream& os, const TennisMatch& tm)
   {
      if (tm.tm_tournamentID.length()) {

         lORr(os, 'r') << "Tourney ID" << " : "; // calling l or r align
         os.unsetf(ios::right);
         lORr(os, 'l') << tm.tm_tournamentID << endl;
         lORr(os, 'r') << "Match ID" << " : ";
         os.unsetf(ios::right);
         lORr(os, 'l') << tm.tm_matchID << endl;
         lORr(os, 'r') << "Tourney" << " : ";
         os.unsetf(ios::right);
         lORr(os, 'l') << tm.tm_tournamentName << endl;
         lORr(os, 'r') << "Winner" << " : ";
         os.unsetf(ios::right);
         lORr(os, 'l') << tm.tm_winnerOfMatch << endl;
         lORr(os, 'r') << "Loser" << " : ";
         os.unsetf(ios::right);
         lORr(os, 'l') << tm.tm_loserOfMatch << endl;
         os.fill(' ');
      }
      else {
         os << "Empty Match";
      }
      return os;
   }

   std::ostream& lORr(ostream& os, const char lORr)
   {
      if (lORr == 'l') {
         os.width(30);
         os.setf(ios::left);
         os.fill('.');
      }
      else {
         os.width(20);
         os.setf(ios::right);
         os.fill('.');
      }
      return os;
   }

   TennisLog::TennisLog(const char* fileName) {
      ifstream fo(fileName);
      if (fo.is_open()) {
         fo.ignore(10000, '\n'); // skipping the 1st line

         while (!fo.eof()) {
            fo.ignore(10000, '\n');
            numberOfMatches++;
         }
         numberOfMatches -= 1; // because the last line is empty, we do not want to include that as a match because system will cound \n as a match
      }
      dynArray = new TennisMatch[numberOfMatches]; // dynamic array of tennis matches
      fo.seekg(0, ios::beg);
      fo.ignore(10000, '\n');
      int counter = 0;



      // ---------------------------Reading file only once---------------------------------------------//

         //TennisMatch matchesArray[10000000];
         //int counter = 0;
         //while (!fo.eof()) {

         //      getline(fo, matchesArray[counter].tm_tournamentID, ',');
         //      getline(fo, matchesArray[counter].tm_tournamentName, ',');
         //      fo >> matchesArray[counter].tm_matchID;
         //      fo.ignore(1);
         //      getline(fo, matchesArray[counter].tm_winnerOfMatch, ',');
         //      getline(fo, matchesArray[counter].tm_loserOfMatch, '\n');
         //      counter++;
         //}

         //dynArray = new TennisMatch[counter - 1];

         //for (int i = 0; i < counter - 1; i++) {
         //   dynArray[i] = matchesArray[i];
         //}

// --------------------------Reading file only once------------------------------------//




      
     // while (!fo.eof()) { // cannot use this as this will include last new line as well.
      for (int i = 0; i < numberOfMatches; i++){ // so using the for loop so that it only works till number of matches (which does not include last empty space)
         getline(fo, dynArray[counter].tm_tournamentID, ',');
         getline(fo, dynArray[counter].tm_tournamentName, ',');
         fo >> dynArray[counter].tm_matchID;
         fo.ignore(1);
         getline(fo, dynArray[counter].tm_winnerOfMatch, ',');
         getline(fo, dynArray[counter].tm_loserOfMatch, '\n');
         counter++;
      }
   }

   TennisLog::TennisLog(const TennisLog& x)
   {
      *this = x;
   }

   TennisLog& TennisLog::operator=(const TennisLog& x)
   {
      if (this != &x) {
         if (x.numberOfMatches) {
            // shallow copy
            numberOfMatches = x.numberOfMatches;

            if (dynArray != nullptr) {
               delete[] dynArray;
            }
            // deep copy
            dynArray = new TennisMatch[x.numberOfMatches];
            
            for (int i = 0; i < numberOfMatches; i++) {
               dynArray[i] = x.dynArray[i];
            }

            //delete[] x.dynArray;
            //x.dynArray = nullptr;
         }
      }
      return *this;
   }

   TennisLog::TennisLog(TennisLog&& x)
   {
      *this = move(x);
   }

   TennisLog& TennisLog::operator=(TennisLog&& x)
   {
      if (this != &x) {
         if (x.numberOfMatches) {
            // shallow copy
            numberOfMatches = x.numberOfMatches;
            // move or deep copy
            delete[] dynArray;
            
            dynArray = x.dynArray;

            x.dynArray = nullptr;
            x.numberOfMatches = 0;
         }
      }
      return *this;
   }

   void TennisLog::addMatch(const TennisMatch& newMatch)
   {

      TennisMatch* tempObj = new TennisMatch[numberOfMatches + 1];

      for (int i = 0; i < numberOfMatches; i++) {
         tempObj[i] = dynArray[i];
      }
      
      tempObj[numberOfMatches] = newMatch;
      ++numberOfMatches;

      if (dynArray != nullptr) {
         delete[] dynArray; // deleting the old dynArr to make +1 array from the tempObj, then delete that tempObj
      }

      dynArray = new TennisMatch[numberOfMatches];

      for (int i = 0; i < numberOfMatches; i++) {
         dynArray[i] = tempObj[i];
      }

      delete[] tempObj;
   }

   TennisLog TennisLog::findMatches(const char* nameOfPlayer)const
   {
      TennisLog newLogToFindMatches;

      for (int i = 0; i < numberOfMatches; i++) {
         if (dynArray[i].tm_loserOfMatch == nameOfPlayer || dynArray[i].tm_winnerOfMatch == nameOfPlayer) {
            newLogToFindMatches.numberOfMatches++;
         }
      }
      newLogToFindMatches.dynArray = new TennisMatch[newLogToFindMatches.numberOfMatches];

      newLogToFindMatches.numberOfMatches = 0;

      for (int i = 0; i < numberOfMatches; i++) {
         if (dynArray[i].tm_loserOfMatch == nameOfPlayer || dynArray[i].tm_winnerOfMatch == nameOfPlayer) {
            
            newLogToFindMatches.dynArray[newLogToFindMatches.numberOfMatches] = dynArray[i]; // assigning the players from 0 to 25000 based on found, into the new object of match array starting from 0 to whatever found. i are not same in square bracket because lets say 1st player found at i = 529, we have to assign that to i = 0 if the new formed array. So, we took the ((  newLogToFindMatches.dynArray[newLogToFindMatches.numberOfMatches]  ))
            
            newLogToFindMatches.numberOfMatches++;
         }
      }
      // when this is returned, the remp nameless obj will be send to the found obj. The dynArray of found will start pointing to (( newLogToFindMatches.dynArray = new TennisMatch[newLogToFindMatches.numberOfMatches]  ))...... So make sure the destructor deletes it...
      
      return newLogToFindMatches; // TennisLog x = newLogToFindMatches
   }

   TennisMatch TennisLog::operator[](const size_t &x)
   {
      if (numberOfMatches) {
         return dynArray[x];
      }
      TennisMatch newEmptyMatch;
      return newEmptyMatch;
   }

   TennisLog::operator size_t()
   {
      return numberOfMatches;
   }

   TennisLog::~TennisLog()
   {
      if (dynArray != nullptr) {
         delete[] dynArray;
      }
   }







}