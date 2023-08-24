#include "Autoshop.h"
#include "Car.h"

using namespace std;
namespace sdds {

   Autoshop& Autoshop::operator+=(Vehicle* theVehicle)
   {
      m_vehicles.push_back(theVehicle);
      return *this;
   }

   void Autoshop::display(std::ostream& out) const
   {
      out << "--------------------------------" << endl;
      out << "| Cars in the autoshop!        |" << endl;
      out << "--------------------------------" << endl;

      for (auto i = m_vehicles.begin(); i != m_vehicles.end(); i++) {
         (*i)->display(out); // (*i)[0].display,,,,,,, (*(*i)).display();
         out << endl;
      }
      out << "--------------------------------" << endl;
   }

   Autoshop::~Autoshop()
   {
      for (Vehicle* vh : m_vehicles) {
         delete vh;
      }
   }


}