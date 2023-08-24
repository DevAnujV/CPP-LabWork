/*
* Name - Anuj Verma
* Seneca Email - averma100@myseneca.ca
* Seneca Student ID - 180483216
* Date of completion - 2023/06/14
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#include <functional>
#include <iostream>
#include "Reservation.h"

using namespace std;

namespace sdds {

   Reservation::Reservation(const std::string& res)
   {
      // Format - 1234: John    ,  john@email.com  ,           2,   3,    5

     // std::size_t pos{};
      std::string::size_type n1{0}; // to hold initial number position
      std::string::size_type n2{0}; // to hold final number position

      n1 = res.find(":", 0); //we are finding the ":" in the string starting from position number - pos. RETURNING position of :
      m_reservation_ID = res.substr(0, n1); // we extracting a string. starting from 0 till the position of ':' and add that string to m_reservation_ID

      removeSpaces(m_reservation_ID);

      n2 = res.find(",", n1); // find , starting from n1 and after whatever lenght it is found, store that number in n2

      n1 = n1 + 1;

      m_nameOfReservation = res.substr(n1, (n2-n1)); // this (x, y) y after substring is how many spaces to go after x. 

      //remove spaces
      removeSpaces(m_nameOfReservation);

      n1 = n2;

      n2 = res.find(",", ++n2); // form 1st , to 2nd , now till email

      n1 = n1 + 1;

      m_emailOfConfirmation = res.substr(n1, (n2-n1)); // this have the email but with the spaces.
      
      // Remove spaces
      removeSpaces(m_emailOfConfirmation);

      std::string newOne = res.substr(++n2);

      m_numberOfpeopleInParty = std::stoi(newOne, &n1);
      n2 = newOne.find(",", n1);
      newOne = newOne.substr(++n2);

      m_checkInDate = std::stoi(newOne, &n1);
      n2 = newOne.find(",", n1);
      newOne = newOne.substr(++n2);

      m_checkInTime = std::stoi(newOne);
   }

   void Reservation::removeSpaces(string& str)
   {
      // code copied from Github to remove leading and trailing spaces.
      str.erase(str.begin(), find_if(str.begin(), str.end(), bind1st(not_equal_to<char>(), ' ')));
      str.erase(std::find_if(str.rbegin(), str.rend(), bind1st(not_equal_to<char>(), ' ')).base(), str.end());
   }


   void Reservation::update(int day, int time)
   {
      m_checkInDate = day;
      m_checkInTime = time;
   }

   ostream& operator<<(std::ostream& ostr, const Reservation& res)
   {
         ostr << "Reservation ";
         ostr.width(10);
         ostr.setf(ios::right);
         ostr << res.m_reservation_ID << ": ";
         ostr.width(20);
         ostr.setf(ios::right);
         ostr << res.m_nameOfReservation << "  ";
         ostr.unsetf(ios::right);
         string email = "<" + res.m_emailOfConfirmation + ">";
         ostr.width(20);
         ostr.setf(ios::left);
         ostr << email;
         ostr.unsetf(ios::left);
         ostr << "    ";
         if (res.m_checkInTime >= 6 && res.m_checkInTime <= 9) {
            ostr << "Breakfast on day ";
         }
         else if (res.m_checkInTime >= 11 && res.m_checkInTime <= 15) {
            ostr << "Lunch on day ";
         }
         else if (res.m_checkInTime >= 17 && res.m_checkInTime <= 21) {
            ostr << "Dinner on day ";
         }
         else {
            ostr << "Drinks on day ";
         }
         
         ostr << res.m_checkInDate << " @ " << res.m_checkInTime << ":00 for " << res.m_numberOfpeopleInParty;

         if (res.m_numberOfpeopleInParty > 1) {

            ostr << " people." << endl;
         }
         else {
            ostr << " person." << endl;
         }

         return ostr;
            
   }
}