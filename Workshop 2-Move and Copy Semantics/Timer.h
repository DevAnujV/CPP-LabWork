/*
* Name - Anuj Verma
* Seneca Email - averma100@myseneca.ca
* Seneca Student ID - 180483216
* Date of completion - 2023/05/28
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#ifndef SDDS_TIMER_H
#define SDDS_TIMER_H

namespace sdds {

   class Timer {
      std::chrono::time_point<std::chrono::steady_clock> startTime;

   public:
      void start();
      long long stop();


   };




}

#endif // !SDDS_TIMER_H
