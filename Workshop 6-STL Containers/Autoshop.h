#ifndef SDDS_AUTOSHOP_H
#define SDDS_AUTOSHOP_H


#include <vector>
#include <list>
#include "Vehicle.h"

namespace sdds {
 
   class Autoshop {

      std::vector<Vehicle*> m_vehicles{}; // vector that have dynamic objects array.
   
   public:
      Autoshop& operator +=(Vehicle* theVehicle);
      void display(std::ostream& out) const;
      virtual ~Autoshop();


      template<typename T>
      void select(T test, std::list<const Vehicle*>& vehicles);
   };


   template<typename T>
   inline void Autoshop::select(T test, std::list<const Vehicle*>&vehicles){
      for (auto i = m_vehicles.begin(); i != m_vehicles.end(); i++) {
         if (test(*i) == true) {
            vehicles.push_back((*i));
         }
      }
   }
}


#endif // !SDDS_AUTOSHOP_H
