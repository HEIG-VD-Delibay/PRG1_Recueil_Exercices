#ifndef STACK_IMPL_H
#define STACK_IMPL_H

#include "Stack.h"
#include <ostream>
#include <sstream>

//-- friends ----------------------------------------------

TODO : retirer ces spécialisations !;

template<typename T>
std::ostream &__display_stack_element(std::ostream &os, T t) {
    return os << t;
}

template<typename T>
std::ostream &__display_stack_element(std::ostream &os, T *t) {
    return os << *t;
};

template<typename T, size_t n>
std::ostream &operator<<(std::ostream &os, const Stack<T, n> &s) {
    for (size_t i = 0; i < s.index; ++i) {
        os << "[" << i << "] ";
        __display_stack_element(os, s.data[i]);
        os << '\n';
    }
    return os;
}

template<typename T, size_t n>
bool operator==(const Stack<T, n> &lhs, const Stack<T, n> &rhs) {
    // deux piles sont égales si elles contiennent le même nombre d'éléments
    // et que ces éléments sont égaux. Le contenu de data à partir de
    // l'indice index n'a pas d'importance.

    return lhs.index == rhs.index and
           std::equal(lhs.data.begin(), lhs.data.begin() + lhs.index, rhs.data.begin());
}

//- class Stack -------------------------------------------

template<typename T, size_t n>
void Stack<T, n>::push(const T &v) {
    data.at(index++) = v;
}

template<typename T, size_t n>
void Stack<T, n>::pop() {
    data.at(--index);
    // Note : accès à data uniquement pour lever une exception
    // en cas de pop() sur une stack vide. sinon --index suffit
}

template<typename T, size_t n>
const T &Stack<T, n>::top() const {
    return data.at(index - 1);
}

template<typename T, size_t n>
Stack<T, n>::operator std::string() const {
    return (std::stringstream() << *this).str();
}

#endif//STACK_IMPL_H
