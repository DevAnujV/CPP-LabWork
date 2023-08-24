#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

#include <iostream>
#include <string>

namespace sdds {

   class Book {
      std::string b_author;
      std::string b_title;
      std::string b_countryOfPublication;
      size_t b_yearOfPublication;
      double b_priceOfBook;
      std::string b_shortSummary;

   public:
      Book() = default;
      const std::string& title() const;
      const std::string& country() const;
      const size_t& year() const;
      double& price();
      Book(const std::string& strBook);
      friend auto operator<<(std::ostream& ostr, const Book& book) ->std::ostream&;

      template <typename T>
      void fixSpelling(T& spellChecker);

   };

   template<typename T>
   inline void Book::fixSpelling(T& spellChecker)
   {
      spellChecker(this->b_shortSummary);
   }

}

#endif // !SDDS_BOOK_H
