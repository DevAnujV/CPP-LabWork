#include <functional>
#include <iomanip>
#include <iostream>
#include<string>
#include "Movie.h"

using namespace std;

namespace sdds {

   const std::string& Movie::title() const
   {
      return m_title;
   }

   Movie::Movie(const std::string& strMovie)
   {
      std::string::size_type n1{ 0 }; // to hold initial number position
      std::string::size_type n2{ 0 }; // to hold final number position

      n1 = strMovie.find(",", 0);
      m_title = strMovie.substr(0, n1);

      // code copied from Github to remove leading and trailing spaces.
      m_title.erase(m_title.begin(), find_if(m_title.begin(), m_title.end(), bind1st(not_equal_to<char>(), ' ')));
      m_title.erase(std::find_if(m_title.rbegin(), m_title.rend(), bind1st(not_equal_to<char>(), ' ')).base(), m_title.end());

      n2 = strMovie.find(",", ++n1);
      std::string tempNumber = strMovie.substr(n1, (n2 - n1));

      m_yearOfRelease = std::stoi(tempNumber);
 
      //b_title = strMovie.substr(n1, (n2 - n1));
      //// code copied from Github to remove leading and trailing spaces.
      //b_title.erase(b_title.begin(), find_if(b_title.begin(), b_title.end(), bind1st(not_equal_to<char>(), ' ')));
      //b_title.erase(std::find_if(b_title.rbegin(), b_title.rend(), bind1st(not_equal_to<char>(), ' ')).base(), b_title.end());
      n1 = n2;

      n2 = strMovie.find("\n", ++n1);
      m_description = strMovie.substr(n1, (n2 - n1));
      // code copied from Github to remove leading and trailing spaces.
      m_description.erase(m_description.begin(), find_if(m_description.begin(), m_description.end(), bind1st(not_equal_to<char>(), ' ')));
      m_description.erase(std::find_if(m_description.rbegin(), m_description.rend(), bind1st(not_equal_to<char>(), ' ')).base(), m_description.end());
   }

   auto operator<<(std::ostream& out, const Movie& movie) -> std::ostream&
   {
      out.width(40);
      out << movie.m_title;
      out << " | ";
      out.width(4);
      out << movie.m_yearOfRelease;
      out << " | " << movie.m_description << endl;
      return out;
   }

}