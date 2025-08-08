#ifndef COLLECTION_IMPL_H
#define COLLECTION_IMPL_H

#include <iostream>
#include <sstream>
#include <algorithm> // find

//---------------------------------------------------------
// friends
//---------------------------------------------------------
template <typename T, template <class, class=std::allocator<T>> class Container>
std::ostream& operator<< (std::ostream& os, const Collection<T, Container>& s) {
   return os << std::string(s);
}

//---------------------------------------------------------
// class Collection
//---------------------------------------------------------
template <typename T, template <class, class=std::allocator<T>> class Container>
Collection<T, Container>::Collection (const Collection<T, Container>& s) {
   this->data  = s.data;
}

//---------------------------------------------------------
template <typename T, template <class, class=std::allocator<T>> class Container>
void Collection<T, Container>::add(const T& v) {
   this->data.push_back(v);
}

//---------------------------------------------------------
template <typename T, template <class, class=std::allocator<T>> class Container>
bool Collection<T, Container>::remove(const T& v) {
   auto it=find(data.begin(), data.end(), v);
   bool is_found = it != data.end();
   if (is_found) {
      this->data.erase(it);
   }
   return is_found;
}

//---------------------------------------------------------
template <typename T, template <class, class=std::allocator<T>> class Container>
void Collection<T, Container>::clear() {
   this->data.erase(data.begin(), data.end());
}

//---------------------------------------------------------
template <typename T, template <class, class=std::allocator<T>> class Container>
bool Collection<T, Container>::empty() const {
   return this->data.empty();
}

//---------------------------------------------------------
template <typename T, template <class, class=std::allocator<T>> class Container>
size_t Collection<T, Container>::size() const {
   return this->data.size();
}

//---------------------------------------------------------
template <typename T, template <class, class=std::allocator<T>> class Container>
Collection<T, Container>::operator std::string() const {
   std::stringstream result;
   result << "[";
   for (auto it=data.begin(); it!=data.end(); ++it) {
      if (it !=data.begin()) result << ", ";
      result << *it;
   }
   result << "]";
   return result.str();
}

#endif //COLLECTION_IMPL_H
