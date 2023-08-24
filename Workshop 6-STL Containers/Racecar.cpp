#include<string>
#include "Racecar.h"
namespace sdds {

   //double& Racecar::showBooster()
   //{
   //   return m_booster;
   //}
   // above was made for dynamic cast....

   Racecar::Racecar(std::istream& in): Car(in)
   {
      std::string tempHolder;
      // Done also as dynamic casting....
      in.ignore(10000, ',');
      std::getline(in, tempHolder, '\n');
      m_booster = std::stod(tempHolder);
      
   }

   void Racecar::display(std::ostream& out) const
   {
      this->Car::display(out);

      out << '*';
      
   }

   double Racecar::topSpeed() const
   {
      return (this->Car::topSpeed() + (m_booster * this->Car::topSpeed()));
   }


}