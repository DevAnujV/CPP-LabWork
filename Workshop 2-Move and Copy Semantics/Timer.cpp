/*
* Name - Anuj Verma
* Seneca Email - averma100@myseneca.ca
* Seneca Student ID - 180483216
* Date of completion - 2023/05/28
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#include <chrono>
#include "Timer.h"

using namespace std::chrono;

namespace sdds {

   void sdds::Timer::start()
   {
      startTime = steady_clock::now();
   }

   long long sdds::Timer::stop()
   {
      const auto endTime = steady_clock::now();

      auto durationTime = duration_cast<nanoseconds>(endTime - startTime).count();

      return durationTime;

   }
   

}
