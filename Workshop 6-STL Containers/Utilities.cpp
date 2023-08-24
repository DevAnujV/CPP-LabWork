#include <fstream>
#include <functional>
#include "Utilities.h"

using namespace std;

namespace sdds {

   Vehicle* createInstance(std::istream& in)
   {
      std::string c_tag{};
     
      std::getline(in, c_tag, ',');
      c_tag.erase(c_tag.begin(), find_if(c_tag.begin(), c_tag.end(), bind1st(not_equal_to<char>(), ' ')));
      c_tag.erase(std::find_if(c_tag.rbegin(), c_tag.rend(), bind1st(not_equal_to<char>(), ' ')).base(), c_tag.end());

  
         if (c_tag == "c" || c_tag == "C") {
            Vehicle* newCar = new Car(in);
            in.ignore(10000, '\n'); // ignoring till \n because we are reading last double value in constructor and \n is yet in file. So, ignoring it so that next read can be done from new line with new car record.
            return newCar;
         }
         else if (c_tag == "r" || c_tag == "R") {
            Vehicle* newRaceCar = new Racecar(in);
            return newRaceCar;
         }
         else if (!c_tag.empty()) {
            in.ignore(10000, '\n');
            throw("Unrecognized record type: [" + c_tag +  "]");
         }
      return nullptr;
   }

}