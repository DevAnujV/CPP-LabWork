/*
* Name - Anuj Verma
* Seneca Email - averma100@myseneca.ca
* Seneca Student ID - 180483216
* Date of completion - 2023/06/14
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_CONFIRMATION_SENDER_H
#define SDDS_CONFIRMATION_SENDER_H

#include "Reservation.h"

namespace sdds {

   class ConfirmationSender {

      const Reservation** confirmReservation = nullptr;
      size_t numberOfConfirmedReservations{0};

   public:
      ConfirmationSender() = default;
      ConfirmationSender& operator+=(const Reservation& res);
      ConfirmationSender& operator-=(const Reservation& res);

      // Rule of 3
      ConfirmationSender(const ConfirmationSender& confSend);
      ConfirmationSender& operator=(const ConfirmationSender& confSend);

      // Rule of 5
      ConfirmationSender(ConfirmationSender&& confSend)noexcept;
      ConfirmationSender& operator=(ConfirmationSender&& confSend) noexcept;
      virtual ~ConfirmationSender();

      friend std::ostream& operator<<(std::ostream& ostr, ConfirmationSender& confirm);
   };



}


#endif // !SDDS_CONFIRMATION_SENDER_H
