#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H

#include<iostream>
#include <string>

namespace sdds {

   template <typename T>
   class Collection {
      std::string c_collectionName;
      T* c_dynArray{};
      size_t c_arrSize{};
      void (*c_observer)(const Collection<T>&, const T&){}; // this is a function pointer

   public:
      Collection(const std::string& name);
      Collection(const Collection& col) = delete;
      auto operator=(const Collection& col)->Collection & = delete;
      virtual ~Collection();
      const std::string& name() const;
      size_t size() const;
      void setObserver(void (*observer)(const Collection<T>&, const T&));
      Collection<T>& operator+=(const T& item);
      T& operator[](size_t idx) const;
      T* operator[](const std::string& title) const;
   };

   template <typename T>
   std::ostream& operator<<(std::ostream& out, const Collection<T>& col){
      for (int i = 0; i < static_cast<int>(col.size()); i++) {
         out << col[i];
      }
      return out;
   }

   template<typename T>
   inline Collection<T>::Collection(const std::string& name)
   {
      c_collectionName = name;
   }

   template<typename T>
   inline Collection<T>::~Collection()
   {
      delete[] c_dynArray;
   }

   template<typename T>
   inline const std::string& Collection<T>::name() const
   {
      return c_collectionName;
   }

   template<typename T>
   inline size_t Collection<T>::size() const
   {
      return c_arrSize;
   }
   template<typename T>

   inline void Collection<T>::setObserver(void(*observer)(const Collection<T>&, const T&)) {
      c_observer = observer;
   }

   template<typename T>
   inline Collection<T>& Collection<T>::operator+=(const T& item)
   {
      bool itemSame = false;
      // adds item to the c_dynArray by making new. 
      for (size_t i = 0; i < c_arrSize && !itemSame; i++) {
         if (item.title() == c_dynArray[i].title()) {
            itemSame = true;
         }
      }

      if (!itemSame) {

         T* storageCollectionTemp{};

         if (c_arrSize >= 1) {

            storageCollectionTemp = new T[c_arrSize];

            for (size_t i = 0; i < c_arrSize; i++) {
               storageCollectionTemp[i] = c_dynArray[i];
            }


            delete[] c_dynArray;
         
         }

         c_arrSize++;

         c_dynArray = new T[c_arrSize];

         for (size_t i = 0; i < (c_arrSize - 1); i++) {

            c_dynArray[i] = storageCollectionTemp[i];
         }

         c_dynArray[c_arrSize - 1] = item;

         // added after 

         delete[] storageCollectionTemp;
         storageCollectionTemp = nullptr;

         // when control reaches here means new item is added
         // calling c_observer

         if (c_observer) {
            c_observer(*this, item);
         }
      }
      return *this;
   }

   template<typename T>
   inline T& Collection<T>::operator[](size_t idx) const
   {
      if (idx < c_arrSize) {
         return c_dynArray[idx];
      }
      throw std::out_of_range("Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(c_arrSize) + "] items.");
   }

   template<typename T>
   inline T* Collection<T>::operator[](const std::string& title) const
   {
      for (size_t i = 0; i < c_arrSize; i++) {
         if (title == c_dynArray[i].title()) {
            return &c_dynArray[i];
         }
      }
      return nullptr;
   }
}

#endif // !SDDS_COLLECTION_H
