/*
* Name - Anuj Verma
* Seneca Email - averma100@myseneca.ca
* Seneca Student ID - 180483216
* Date of completion - 2023/06/14
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.



// manages a SINGLE reservation of a restaurant

#ifndef SDDS_RESERVATION_H
#define SDDS_RESERVATION_H

#include <string>

namespace sdds {

   class Reservation {

      std::string m_reservation_ID{};
      std::string m_nameOfReservation{};
      std::string m_emailOfConfirmation{};
      unsigned m_numberOfpeopleInParty{};
      unsigned m_checkInDate{};
      unsigned m_checkInTime{};

   public:
      Reservation() = default;
      Reservation(const std::string& res);
      void removeSpaces(std::string& str);
      void update(int day, int time);
      
      friend std::ostream& operator<<(std::ostream& ostr, const Reservation& res);
   };


}

#endif // !SDDS_RESERVATION_H
