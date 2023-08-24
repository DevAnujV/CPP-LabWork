/*
* Name - Anuj Verma
* Seneca Email - averma100@myseneca.ca
* Seneca Student ID - 180483216
* Date of completion - 2023/06/14
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#ifndef SDDS_RESTAURANT_H
#define SDDS_RESTAURANT_H

#include <iostream>
#include "Reservation.h"

namespace sdds {

   class Restaurant {

      Reservation** restaurantReservations{};
      size_t m_cnt;

   public:
      Restaurant(const Reservation* reservations[], size_t cnt); // this is so that now restaurant can manage all the reservations.
      // rule of 3
      Restaurant(const Restaurant& rest);
      Restaurant& operator=(const Restaurant& rest);

      // Rule of 5
      Restaurant(Restaurant&& rest);
      Restaurant& operator=(Restaurant&& rest);
      virtual ~Restaurant();

      size_t size();

      friend std::ostream& operator<<(std::ostream& ostr, const Restaurant& rest);
   };
}

#endif // !SDDS_RESTAURANT_H
