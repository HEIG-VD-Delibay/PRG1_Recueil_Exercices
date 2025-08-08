#ifndef COLLECTION_H
#define COLLECTION_H

#include <string>

//---------------------------------------------------------
template <typename T, template <class, class=std::allocator<T>> class Container>
class Collection;

//---------------------------------------------------------
template <typename T, template <class, class=std::allocator<T>> class Container>
std::ostream& operator<< (std::ostream& os, const Collection<T, Container>& s);

//---------------------------------------------------------
template <typename T, template <class, class=std::allocator<T>> class Container>
class Collection {

friend std::ostream& operator<< <>(std::ostream& os, const Collection<T, Container>& s);

public:
   Collection () = default;
   Collection (const Collection& s);
   void   add   (const T&  v);
   bool   remove(const T&  v);
   void   clear ();
   bool   empty () const;
   size_t size  () const;

   explicit operator std::string() const;

private:
   Container<T> data;
};

#include "Collection_Impl.h"

#endif //COLLECTION_H
