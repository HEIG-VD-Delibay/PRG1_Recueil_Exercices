#include <iostream>
#include <vector>

#include "Stack.h"

using namespace std;

int main() {

    const vector data = {0, 1, 2, 3, 4, 5};

    // int
    Stack<int, 10> s1;
    for (int i: data) {
        s1.push(i);
    }
    cout << s1 << endl;

    // const int*
    Stack<const int *, 10> s2;
    for (const int &i: data) {
        s2.push(&i);
    }
    cout << string(s2) << endl;
}
