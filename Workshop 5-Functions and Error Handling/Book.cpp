#include <functional>
#include <iomanip>
#include "Book.h"

using namespace std;

namespace sdds {

   const string& Book::title() const{
      return b_title;
   }

   const std::string& Book::country() const{
      return b_countryOfPublication;
   }

   const size_t& Book::year() const{
      return b_yearOfPublication;
   }

   double& Book::price(){
      return b_priceOfBook;
   }

   Book::Book(const std::string& strBook){

      std::string::size_type n1{ 0 }; // to hold initial number position
      std::string::size_type n2{ 0 }; // to hold final number position

      n1 = strBook.find(",", 0);
      b_author = strBook.substr(0, n1);
      
      // code copied from Github to remove leading and trailing spaces.
      b_author.erase(b_author.begin(), find_if(b_author.begin(), b_author.end(), bind1st(not_equal_to<char>(), ' ')));
      b_author.erase(std::find_if(b_author.rbegin(), b_author.rend(), bind1st(not_equal_to<char>(), ' ')).base(), b_author.end());

      n2 = strBook.find(",", ++n1);
      b_title = strBook.substr(n1, (n2 - n1));
      // code copied from Github to remove leading and trailing spaces.
      b_title.erase(b_title.begin(), find_if(b_title.begin(), b_title.end(), bind1st(not_equal_to<char>(), ' ')));
      b_title.erase(std::find_if(b_title.rbegin(), b_title.rend(), bind1st(not_equal_to<char>(), ' ')).base(), b_title.end());

      n1 = n2;
      n2 = strBook.find(",", ++n1);
      b_countryOfPublication = strBook.substr(n1, (n2 - n1));
      // code copied from Github to remove leading and trailing spaces.
      b_countryOfPublication.erase(b_countryOfPublication.begin(), find_if(b_countryOfPublication.begin(), b_countryOfPublication.end(), bind1st(not_equal_to<char>(), ' ')));
      b_countryOfPublication.erase(std::find_if(b_countryOfPublication.rbegin(), b_countryOfPublication.rend(), bind1st(not_equal_to<char>(), ' ')).base(), b_countryOfPublication.end());

      n1 = n2;
      n2 = strBook.find(",", ++n1);
      b_priceOfBook = std::stod(strBook.substr(n1, (n2 - n1)));

      n1 = n2;
      n2 = strBook.find(",", ++n1);
      b_yearOfPublication = std::stod(strBook.substr(n1, (n2 - n1)));

      n1 = n2;
      n2 = strBook.find(".", ++n1);
      b_shortSummary = strBook.substr(n1, (n2 - n1)+1);
      // code copied from Github to remove leading and trailing spaces.
      b_shortSummary.erase(b_shortSummary.begin(), find_if(b_shortSummary.begin(), b_shortSummary.end(), bind1st(not_equal_to<char>(), ' ')));
      b_shortSummary.erase(std::find_if(b_shortSummary.rbegin(), b_shortSummary.rend(), bind1st(not_equal_to<char>(), ' ')).base(), b_shortSummary.end());
   }

   auto operator<<(std::ostream& ostr, const Book& book) -> std::ostream&
   {
      ostr << setfill(' ') << setw(20) << book.b_author << " | " << setfill(' ') << setw(22) << book.b_title << " | " << setfill(' ') << setw(5) << book.b_countryOfPublication << " | "
         << setfill(' ') << setw(4) << book.b_yearOfPublication << " | " << setfill(' ') << setw(6) << fixed << setprecision(2) << book.b_priceOfBook << " | " << book.b_shortSummary << endl;
      return ostr;
   }

}