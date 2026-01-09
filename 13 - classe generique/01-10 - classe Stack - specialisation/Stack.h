#ifndef STACK_H
#define STACK_H

#include <array>
#include <string>

//- Pré-déclarations --------------------------------------
template<typename T, size_t n>
class Stack;
template<typename T, size_t n>
std::ostream &operator<<(std::ostream &os, const Stack<T, n> &s);
template<typename T, size_t n>
bool operator==(const Stack<T, n> &lhs, const Stack<T, n> &rhs);

//--class Stack --------------------------------------------

template<typename T, size_t n = 100>
class Stack {

    friend std::ostream &operator<< <>(std::ostream &os, const Stack &s);
    friend bool operator== <>(const Stack &lhs, const Stack &rhs);

public:
    Stack() : index{}, data{} {}
    // Constructeur de copie pas nécessaire. la version par défaut suffit

    // méthodes définies dans Stack_Impl.h
    void push(const T &v);
    void pop();
    const T &top() const;

    // méthodes triviales définies en ligne
    bool full() const { return index == n; }
    bool empty() const { return index == 0; }
    size_t size() const { return index; }
    size_t capacity() const { return n; }

    // conversion explicite Stack -> string
    explicit operator std::string() const;

private:
    size_t index;
    std::array<T, n> data;
};

#include "Stack_Impl.h"

#endif//STACK_H
