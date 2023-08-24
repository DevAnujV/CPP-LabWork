#ifndef SDDS_QUEUE_H
#define SDDS_QUEUE_H

#include <iostream>
#include "Dictionary.h"


namespace sdds {
   
   template <typename T, int t_capacity>
   class Queue {
    protected:
      T arrayOfObject[t_capacity]{};
      // Dictionary arrayOfObjects[50]...... class Object array
      int numberOfObjectsBeingStored = 0;
      static T Emptyobj;
   public:
      virtual bool push(const T& item);
      T pop();
      int size()const;
      void display(std::ostream& ostr = std::cout)const;
      T operator[](int) const;
      virtual ~Queue(){};
   };


   template<typename T, int t_capacity>
   T Queue<T, t_capacity>::Emptyobj{};


   template<typename T, int t_capacity>
   bool Queue<T, t_capacity>::push(const T& item)
   {
      if (numberOfObjectsBeingStored <= t_capacity) {
         arrayOfObject[numberOfObjectsBeingStored] = item;
         numberOfObjectsBeingStored++;
         return true;
      }
      return false;
   }

   template<typename T, int t_capacity>
   T  Queue<T, t_capacity>::pop()
   {
      T tempObj = arrayOfObject[0];

      for (int i = 0; i <= numberOfObjectsBeingStored-2; i++) {
         arrayOfObject[i] = arrayOfObject[i + 1];
      }
      arrayOfObject[numberOfObjectsBeingStored - 1] = {};
      numberOfObjectsBeingStored--;
      return tempObj;
   }

   template<typename T, int t_capacity>
   int  Queue<T, t_capacity>::size()const
   {
      return numberOfObjectsBeingStored;
   }

   template<typename T, int t_capacity>
   void  Queue<T, t_capacity>::display(std::ostream& ostr) const
      // for dictionary =   
      // 
      // void display(std::ostream& ostr)
      // cout << dict[0];
   {
      ostr << "----------------------" << std::endl;
      ostr << "| Dictionary Content |" << std::endl;
      ostr << "----------------------" << std::endl;

      for (int i = 0; i < numberOfObjectsBeingStored; i++) {
         ostr << arrayOfObject[i] << std::endl;
      }
      ostr << "----------------------" << std::endl;
   }

   template<typename T, int t_capacity>
   T  Queue<T, t_capacity>::operator[](int index) const
   {
      if (index < numberOfObjectsBeingStored) {
         return arrayOfObject[index];
      }
      return Emptyobj;
   }


   // specialisation

   template<>
      Dictionary Queue<Dictionary, 100>::Emptyobj("Empty Term", "Empty Substitute");

}

#endif // !SDDS_QUEUE_H
