/*
* Name - Anuj Verma
* Seneca Email - averma100@myseneca.ca
* Seneca Student ID - 180483216
* Date of completion - 2023/06/14
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#include "Restaurant.h"

using namespace std;

namespace sdds {

   Restaurant::Restaurant(const Reservation* reservations[], size_t cnt) {
      
      restaurantReservations = new Reservation * [cnt];
      m_cnt = cnt;

      for (size_t i = 0; i < cnt; i++) {
         restaurantReservations[i] = new Reservation(*reservations[i]); // this is new reservation being made based on *reservations[i]. 
         // One arg constructuctor accepting. This is done by default as no deep copy needed. Out members are no dynamic.
      }
   }

   Restaurant::Restaurant(const Restaurant& rest)
   {
      *this = rest;
   }

   Restaurant& Restaurant::operator=(const Restaurant& rest)
   {
      // 1. check for self assignment
      if (&rest != this) {

         // 2. clean up
         if (restaurantReservations != nullptr) {
            for (size_t i = 0; i < m_cnt; i++) {
               delete restaurantReservations[i];
               restaurantReservations[i] = nullptr;
            }
            delete[] restaurantReservations;
            restaurantReservations = nullptr;
         }

         // 3. shallow copy
         m_cnt = rest.m_cnt;

         // 4. Deep copy
         if (m_cnt > 0) {
            restaurantReservations = new Reservation * [rest.m_cnt] {};

            for (size_t i = 0; i < rest.m_cnt; i++) {
               restaurantReservations[i] = new Reservation(*rest.restaurantReservations[i]);
            }
         }
      }
      return *this;
   }

   Restaurant::Restaurant(Restaurant&& rest)
   {
      *this = move(rest);
   }

   Restaurant& Restaurant::operator=(Restaurant&& rest)
   {
      if (&rest != this) {
         if (rest.m_cnt) {

            if (restaurantReservations != nullptr) {
               for (size_t i = 0; i < m_cnt; i++) {
                  delete restaurantReservations[i];
               }
               delete[] restaurantReservations;
            }

            restaurantReservations = rest.restaurantReservations;
            rest.restaurantReservations = nullptr;
            m_cnt = rest.m_cnt;
            rest.m_cnt = 0;
         }
      }

      return *this;
   }

   Restaurant::~Restaurant()
   {
      for (size_t i = 0; i < m_cnt; i++) {
         delete restaurantReservations[i];
      }
      delete[] restaurantReservations;
   }

   size_t Restaurant::size()
   {
      return m_cnt;
   }

   std::ostream& operator<<(std::ostream& ostr, const Restaurant& rest)
   {
      static size_t CALL_CNT{};
      CALL_CNT++;

      ostr << "--------------------------" << endl;
      ostr << "Fancy Restaurant (" << CALL_CNT << ")" << endl;
      ostr << "--------------------------" << endl;

      if (rest.m_cnt) {

         for (size_t i = 0; i < rest.m_cnt; i++) {
            ostr << *rest.restaurantReservations[i];
         }
      }

      else {
         ostr << "This restaurant is empty!" << endl;
      }

      ostr << "--------------------------" << endl;
      return ostr;
   }

}