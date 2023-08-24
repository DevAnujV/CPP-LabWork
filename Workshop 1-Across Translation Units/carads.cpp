/*
* Name - Anuj Verma
* Seneca Email - averma100@myseneca.ca
* Seneca Student ID - 180483216
* Date of completion - 2023/05/21
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include "carads.h"


using namespace std;

double g_taxrate;
double g_discount;

namespace sdds {

   int listArgs(int argc, char** argv)
   {
      cout << "Command Line:" << endl << "--------------------------" << endl;

      for (int i = 0; i < argc; ++i) {
         cout << "  " << i + 1 << ": " << argv[i] << endl;
      }
      cout << "--------------------------" << endl << endl;
         return argc;
   }

   std::istream& operator>>(std::istream& is, Cars& car)
   {
      car.read(is);
      return is;
   }

   void operator>>(const Cars& car1, Cars& car2)
   {
      car2 = car1;
   }

   Cars::Cars(const Cars& c)
   {
      *this = c;
   }

   Cars& Cars::operator=(const Cars& c)
   {
      if (this != &c) {
         if (c.manufactureYear) {
            // shallow copy
            discount = c.discount;
            manufactureYear = c.manufactureYear;
            strcpy(modelOfCar,c.modelOfCar);
            priceOfCar = c.priceOfCar;
            statusOfCar = c.statusOfCar;
            
            // deep copy
            brandOfCar = new char[strlen(c.brandOfCar) + 1]; // mem allocated here.....
            strcpy(brandOfCar, c.brandOfCar);
         }
      }
      return *this;
   }

   Cars::~Cars()
   {
      if (brandOfCar && brandOfCar[0])
         delete[] brandOfCar; // not deleting here because deleted by display function...
      
   }

   void Cars::read(std::istream& is)
   {
      is.get(statusOfCar);
      is.ignore(1);

      std::string temp;
      //is >> temp;
      getline(is, temp, ','); // getline is used this way for string..


      // deallocate here, it will be made for all the array of car objects


      brandOfCar = new char[temp.length() + 1]; // string function is this string.length()
      strcpy(brandOfCar, temp.c_str()); // we can copy a string into char[] using string.c_str() to make it compatible with strcpy function.
      
      //is.getline(brandOfCar, 10, ',');
      is.getline(modelOfCar, 15, ',');
      is >> manufactureYear;
      is.ignore(1);
      is >> priceOfCar;
      is.ignore(1);
      char disc;
      is >> disc; disc == 'Y' ? discount = true : discount = false;
      is.ignore(10000, '\n');
   }

   void Cars::display(bool reset)
   {

      if (this->manufactureYear) {

         static int counter = 1;
         
         if (reset == true) {
            counter = 1;
            this->again = false;
         }

         cout.setf(ios::left);
         cout.width(2);
         cout << counter++ << ". ";
         cout.width(10);
         cout << brandOfCar << "| ";

         // once displayed, I can remove the memory of this brandOfCar because, after this, the current car is not being used anywhere

         if (this->again){
           delete[] brandOfCar;
           brandOfCar = nullptr;
         }

         cout.width(15);
         cout << modelOfCar << "| ";
         cout << manufactureYear << " |";
         cout.unsetf(ios::left);
         cout.width(12);
         cout.setf(ios::right);
         std::cout << std::fixed;
         std::cout << std::setprecision(2);
         cout << priceOfCar + (priceOfCar * g_taxrate) << "|";
         cout.unsetf(ios::right);

         if (this->discount) {
            cout.width(12);
            cout.setf(ios::right);
            cout << ((priceOfCar + (priceOfCar * g_taxrate)) - ((priceOfCar + (priceOfCar * g_taxrate)) * g_discount));
         }
         cout.unsetf(ios::right);
         cout << endl;



      }
      else {
         cout << "COUNTER. No Car";
      }
   }

   char Cars::getStatus()
   {
      return this->statusOfCar;
   }

   Cars::operator bool() const
   {
      return (this->statusOfCar == 'N');
   }

}