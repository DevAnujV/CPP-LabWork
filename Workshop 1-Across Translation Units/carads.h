/*
* Name - Anuj Verma
* Seneca Email - averma100@myseneca.ca
* Seneca Student ID - 180483216
* Date of completion - 2023/05/21
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef _SDDS_CARADS_H
#define _SDDS_CARADS_H

extern double g_taxrate;
extern double g_discount;

namespace sdds {

   int listArgs(int argc, char** argv);

   class Cars {
      char* brandOfCar{};
      char modelOfCar[15]{};
      int manufactureYear{};
      double priceOfCar{};
      char statusOfCar{}; // user U or new N
      bool discount; // true or false if on discount
      bool again = true;

   public:
      Cars() = default;
      Cars(const Cars& c);
      Cars& operator=(const Cars& c);
      ~Cars();
      void read(std::istream& is);
      void display(bool reset);
      char getStatus();
      operator bool()const;
   };

   std::istream& operator>>(std::istream& is, Cars& car);
   void operator>>(const Cars& car1, Cars& car2);


}




#endif // !_SDDS_CARADS_H

