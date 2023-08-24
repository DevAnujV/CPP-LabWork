#include<functional>
#include "SpellChecker.h"

using namespace std;

namespace sdds {

   SpellChecker::SpellChecker(const char* filename)
   {
      
      std::ifstream file(filename);
      if (file.is_open()) {
         size_t counter{ 0 };
         while (!file.eof()) {
            string tempStore;
               std::getline(file, tempStore, '\n');
               if (tempStore.length() > 1) {
               size_t offset = tempStore.find(' ', 0);
               sc_badWords[counter] = tempStore.substr(0, offset++);
               // code copied from Github to remove leading and trailing spaces.
               sc_badWords[counter].erase(sc_badWords[counter].begin(), find_if(sc_badWords[counter].begin(), sc_badWords[counter].end(), bind1st(not_equal_to<char>(), ' ')));
               sc_badWords[counter].erase(std::find_if(sc_badWords[counter].rbegin(), sc_badWords[counter].rend(), bind1st(not_equal_to<char>(), ' ')).base(), sc_badWords[counter].end());

               sc_goodWords[counter] = tempStore.substr(offset);
               // code copied from Github to remove leading and trailing spaces.
               sc_goodWords[counter].erase(sc_goodWords[counter].begin(), find_if(sc_goodWords[counter].begin(), sc_goodWords[counter].end(), bind1st(not_equal_to<char>(), ' ')));
               sc_goodWords[counter].erase(std::find_if(sc_goodWords[counter].rbegin(), sc_goodWords[counter].rend(), bind1st(not_equal_to<char>(), ' ')).base(), sc_goodWords[counter].end());
               counter++;
            }
         }
      }
      else {
         throw "Bad file name!";
      }
   }

   void SpellChecker::operator()(std::string& text){
      for (int i = 0; i < 6; i++) {
         std::string::size_type n{};
         do {
             n = text.find(sc_badWords[i], n++);
             if (n != std::string::npos) {
                text.replace(n, sc_badWords[i].length(), sc_goodWords[i]);
                wordsCount[i]++;
             }

         } while (n != std::string::npos);
      }
   }

   void SpellChecker::showStatistics(std::ostream& out) const
   {
      out << "Spellchecker Statistics" << endl;
      for (int i = 0; i < 6; i++) {
         out.width(15);
         out.setf(ios::right);
         out << sc_badWords[i];
         out << ": " << wordsCount[i] << " replacements" << endl;
      }
   }


}