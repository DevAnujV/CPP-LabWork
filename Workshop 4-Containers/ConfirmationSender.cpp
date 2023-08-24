/*
* Name - Anuj Verma
* Seneca Email - averma100@myseneca.ca
* Seneca Student ID - 180483216
* Date of completion - 2023/06/14
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <cstdlib>
#include <iostream>
#include "ConfirmationSender.h"

using namespace std;

namespace sdds {

   ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res)
   {
      bool skip = false;

      for (size_t i = 0; i < numberOfConfirmedReservations && !skip; i++) {
         if (confirmReservation[i] == &res) {
            skip = true;
         }
      }

      if (!skip) {
         const Reservation** storePreviousReservations{};
 
         storePreviousReservations = confirmReservation;

         numberOfConfirmedReservations++;

         confirmReservation = new const Reservation * [numberOfConfirmedReservations];

         for (size_t i = 0; i < (numberOfConfirmedReservations - 1); i++) {

            confirmReservation[i] = storePreviousReservations[i];
         }

         confirmReservation[numberOfConfirmedReservations - 1] = &res;

         // added after 

         delete[] storePreviousReservations;
         storePreviousReservations = nullptr;
      }
      return *this;
   }

   ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res)
   {
      for (size_t i = 0; i < numberOfConfirmedReservations; i++) {
         if (confirmReservation[i] == &res) {
            //delete confirmReservation[i];
            confirmReservation[i] = nullptr;
           // numberOfConfirmedReservations--;
         }
      }

      //if (numberOfConfirmedReservations > 0) {

      //   const Reservation** newResv;
      //   newResv = confirmReservation;

      //   confirmReservation = new const Reservation * [numberOfConfirmedReservations];

      //   for (int i = 0, j = 0; i < static_cast<int>(numberOfConfirmedReservations)+1; i++) {
      //      if (newResv[i] != nullptr) {
      //         confirmReservation[j] = newResv[i];
      //         j++;
      //      }
      //   }
      //   // just to be safe
      //   delete[] newResv;   // not sure if this one is needed !!!
      //}

      return *this;
   }

   ostream& operator<<(std::ostream& ostr, ConfirmationSender& confirm) {

      ostr << "--------------------------" << endl << "Confirmations to Send" << endl << "--------------------------" << endl;

      if (confirm.numberOfConfirmedReservations == 0) {
         cout << "There are no confirmations to send!" << endl;
      }
      else {
         for (size_t i = 0; i < confirm.numberOfConfirmedReservations; i++) {
            if (confirm.confirmReservation[i] != nullptr) {
               ostr << *confirm.confirmReservation[i];
            }
         }
      }

      ostr << "--------------------------" << endl;
      return ostr;
   }

   ConfirmationSender::ConfirmationSender(const ConfirmationSender& confSend) {
      *this = confSend;
   }

   ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& confSend) {
      if (this != &confSend) {
         if (confSend.numberOfConfirmedReservations) {
            numberOfConfirmedReservations = confSend.numberOfConfirmedReservations;
            // Because this class cannot make new Object of Resrervation, we have to make both of them point to same
            // but use a flag in destructor, that if one is nullptr, then dont delete...
            if (confirmReservation != nullptr) {
               for (size_t i = 0; i < numberOfConfirmedReservations; i++) {
                  delete confirmReservation[i];
               }
               delete[] confirmReservation;
            }


            confirmReservation = new const Reservation * [numberOfConfirmedReservations];
            
            for (size_t i = 0; i < numberOfConfirmedReservations; i++) {
               confirmReservation[i] = confSend.confirmReservation[i];
            }
         }
      }
      return *this;
   }

   ConfirmationSender::ConfirmationSender(ConfirmationSender&& confSend)noexcept {
      *this = move(confSend);
   }

   ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& confSend)noexcept {
      if (this != &confSend) {

         if (confirmReservation != nullptr) {
            for (size_t i = 0; i < numberOfConfirmedReservations; i++) {
               delete confirmReservation[i];
            }
            //  delete[] confirmReservation;
         }

         numberOfConfirmedReservations = confSend.numberOfConfirmedReservations;
         if (numberOfConfirmedReservations > 0) {
            confirmReservation = confSend.confirmReservation;
            confSend.confirmReservation = nullptr;
            confSend.numberOfConfirmedReservations = 0;
         }
      }
      return *this;
   }

   ConfirmationSender::~ConfirmationSender() {

     // delete[] confirmReservation;

      if (confirmReservation != nullptr) {
         //for (size_t i = 0; i < numberOfConfirmedReservations; i++) {
         //   if (confirmReservation[i] != nullptr) {
         //      delete confirmReservation[i];
         //      confirmReservation[i] = nullptr;
         //   }
         //}
         delete[] confirmReservation;
        // confirmReservation = nullptr;
      }
   }



}