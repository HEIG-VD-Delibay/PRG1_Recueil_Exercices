#ifndef STACK_IMPL_H
#define STACK_IMPL_H

#include "Stack.sol.h"// pour faciliter la vie de l'IDE
#include <iostream>

//---------------------------------------------------------
template<typename T, size_t n>
void Stack<T, n>::push(const T &v) {
    data.at(index++) = v;
}

//---------------------------------------------------------
template<typename T, size_t n>
void Stack<T, n>::pop() {
    data.at(--index);
    // Note : accès à data uniquement pour lever une exception
    // en cas de pop() sur une stack vide
}

//---------------------------------------------------------
template<typename T, size_t n>
const T &Stack<T, n>::top() const {
    return data.at(index - 1);
}

//---------------------------------------------------------
template<typename T, size_t n>
void Stack<T, n>::display() const {
    using std::cout, std::endl;

    cout << "size : " << index << endl;
    cout << "data : ";

    cout << "[";
    for (size_t i = 0; i < index; ++i) {
        if (i) cout << ", ";
        cout << data[i];
    }
    cout << "]" << endl;
}

#endif//STACK_IMPL_H
