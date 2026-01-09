#include "Stack.sol.h"
#include <iostream>

using namespace std;

int main() {
    Stack<int, 10> s;
    for (int i = 0; i < 6; ++i) {
        s.push(i);
    }

    // cast Stack<T, n> => string
    cout << string(s) << endl;

    // constructeur par copie
    Stack copie(s);

    // opérateur de flux <<
    cout << copie << endl;

    // opérateur ==
    cout << boolalpha << (s == copie) << endl;
}
