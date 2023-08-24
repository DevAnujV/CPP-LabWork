#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H

#include <iostream>

namespace sdds {

   class Movie {

      std::string m_title;
      int m_yearOfRelease;
      std::string m_description;
   public:
      Movie() = default;
      const std::string& title() const;
      Movie(const std::string& strMovie);
      auto friend operator<<(std::ostream& out, const Movie& movie)->std::ostream&;

      template<typename T>
      void fixSpelling(T& spellChecker);
   };

   template<typename T> // try T of spellChecker class here
   inline void Movie::fixSpelling(T& spellChecker){
      spellChecker(this->m_title);
      spellChecker(this->m_description);
   }
}

#endif // !SDDS_MOVIE_H
