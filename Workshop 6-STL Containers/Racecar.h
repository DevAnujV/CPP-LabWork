#ifndef SDDS_RACECAR_H
#define SDDS_RACECAR_H

#include "Car.h"

namespace sdds {

   class Racecar: public Car {
      double m_booster;
   public:
      //double& showBooster(); in case of dynamic casting
      Racecar(std::istream& in);
      void display(std::ostream& out) const;
      double topSpeed() const;
   };
}
#endif // !SDDS_RACECAR_H
