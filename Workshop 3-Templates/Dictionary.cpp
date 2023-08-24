#include "Dictionary.h"

namespace sdds {

   std::ostream& operator<<(std::ostream& ostr, const Dictionary& dict)
   {
      ostr.width(20);
      ostr.setf(std::ios::right);
      ostr << dict.getTerm();
      ostr.unsetf(std::ios::right);
      ostr << ": " << dict.getDefinition();
      return ostr;
   }

   bool Dictionary::operator==(const Dictionary& dict) {
      return this->getTerm() == dict.getTerm();
   }


}