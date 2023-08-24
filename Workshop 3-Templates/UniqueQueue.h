#ifndef SDDS_UNIQUEQUEUE_H
#define SDDS_UNIQUEQUEUE_H

#include <math.h>
#include "Queue.h"

namespace sdds {

   template<typename T>
   class UniqueQueue : public Queue<T, 100> {
   public:
      UniqueQueue() = default;
      UniqueQueue(const UniqueQueue<T>& newUniqueQueue) = delete;
      UniqueQueue<T> operator=(const UniqueQueue<T>& newUniqueQueue) = delete;

      bool push(const T& item);
   };


   template<typename T>
   bool UniqueQueue<T>::push(const T& item) {
      if (this->size() < 100) {
         
         for (int i = 0; i < this->size(); i++) {
            if (this->arrayOfObject[i] == item) {
               return false;
            }
         }
         this->arrayOfObject[this->size()] = item;
         this->numberOfObjectsBeingStored++;
         return true;
      }
         return false;
   }

   // Can we done with template specialization too but operator overlading will work too(done in dictionary.cpp)...

   //template <>
   //bool UniqueQueue<Dictionary>::push(const Dictionary& item) {
   //   if (this->size() < 100) {


   //      for (int i = 0; i < this->size(); i++) {
   //         if (arrayOfObject[i].getTerm() == item.getTerm()) {
   //            return false;
   //         }
   //      }
   //      this->arrayOfObject[this->size()] = item;
   //      this->numberOfObjectsBeingStored++;
   //      return true;
   //   }
   //   return false;
   //}

   template<>
   bool UniqueQueue<double>::push(const double& num) {
         if (this->size() < 100) {

              for (int i = 0; i < this->size(); i++) {
                 if (abs(arrayOfObject[i] - num) <= 0.005) {
                    return false;
                 }
              }
              this->arrayOfObject[this->size()] = num;
              this->numberOfObjectsBeingStored++;
              return true;
           }
           return false;
        }




}

#endif // !SDDS_UNIQUEQUEUE_H
