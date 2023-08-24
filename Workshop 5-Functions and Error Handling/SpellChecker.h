#ifndef SDDS_SPELLCHECKER_H
#define SDDS_SPELLCHECKER_H

#include <iostream>
#include <fstream>
#include <string>

namespace sdds {

   class SpellChecker {

      std::string sc_badWords[6];
      std::string sc_goodWords[6];
      int wordsCount[6]{};
   public:
      SpellChecker(const char* filename);
      void operator()(std::string& text);
      void showStatistics(std::ostream& out) const;
   };
}
#endif // 
