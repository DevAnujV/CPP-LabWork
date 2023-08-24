#ifndef SDDS_CAR_H
#define SDDS_CAR_H

#include <fstream>
#include "Vehicle.h"


namespace sdds {
   class Car : public Vehicle {
      std::string c_tag;
      std::string c_maker{};
      std::string c_condition{};
      double c_topSpeed{};
   
   public:

      Car(std::istream& cinRef);
      std::string condition() const;
      double topSpeed() const;
      std::string whatTag()const;
      void display(std::ostream& out) const;
   };
}
#endif // !SDDS_CAR_H
