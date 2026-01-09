#ifndef STACK_H
#define STACK_H

#include <array>
#include <cstddef>

template<typename T, size_t n = 100>
class Stack {

public:
    Stack() : index{}, data{} {}

    // méthodes définies dans Stack_Impl.h
    void push(const T &v);
    void pop();
    const T &top() const;
    void display() const;

    // méthodes triviales définies en ligne
    bool full() const { return index == n; }
    bool empty() const { return index == 0; }
    size_t size() const { return index; }
    size_t capacity() const { return n; }

private:
    size_t index;
    std::array<T, n> data;
};

#include "Stack_Impl.sol.h"

#endif//STACK_H
