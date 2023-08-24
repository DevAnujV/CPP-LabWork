#include <string>
#include<functional>
#include<iomanip>
#include <typeinfo>
#include "Car.h"

using namespace std;
namespace sdds {

   Car::Car(std::istream& cinRef)
   {
      std::getline(cinRef, c_maker, ',');
      
      c_maker.erase(c_maker.begin(), find_if(c_maker.begin(), c_maker.end(), bind1st(not_equal_to<char>(), ' ')));
      c_maker.erase(std::find_if(c_maker.rbegin(), c_maker.rend(), bind1st(not_equal_to<char>(), ' ')).base(), c_maker.end());

      std::getline(cinRef, c_condition, ',');
      c_condition.erase(c_condition.begin(), find_if(c_condition.begin(), c_condition.end(), bind1st(not_equal_to<char>(), ' ')));
      c_condition.erase(std::find_if(c_condition.rbegin(), c_condition.rend(), bind1st(not_equal_to<char>(), ' ')).base(), c_condition.end());

      if (c_condition.empty()) {
         c_condition = "n";
      }

      else if (!(c_condition == "n" || c_condition == "u" || c_condition == "b")) {
         cinRef.ignore(10000, '\n'); // ignore is being done because once we found error in record, we dont want to keep reading and want to go to new line.
         throw ("Invalid record!");
      }

      cinRef >> c_topSpeed;

      if (!cinRef) {
         cinRef.clear(); // if even for once, cin of file gets in error stage, it will not read from file anymore, basically file will close.....
         cinRef.ignore(10000, '\n');
         throw("Invalid record!");
      }
   }

   std::string Car::condition() const
   {
      return c_condition;
   }

   double Car::topSpeed() const
   {
      return c_topSpeed;
   }

   std::string Car::whatTag()const
   {
      return c_tag;
   }

   void Car::display(std::ostream& out) const
   {
      out << "| ";
      out.width(10);
      out << c_maker;
      out << " | ";

      out.width(6);
      out.setf(ios::left);
      if (c_condition == "n") {
         out << "new";
      }
      else if (c_condition == "u") {
         out << "used";
      }
      else {
         out << "broken";
      }
      out.unsetf(ios::left);
      
      out << " | ";

      out << setw(6) << fixed << setprecision(2) << topSpeed();
      out << " |";
   }


}