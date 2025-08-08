#include <iostream>

using namespace std;

int main() {
    MonEntier m0, m1(1), m2 = 5;
    const MonEntier m3{7};

    cout << m0 << endl
         << m1 << endl;

    cout << boolalpha;
    cout << (m0 == m1) << endl;
    cout << (m0 != m1) << endl;
    cout << noboolalpha;

    cout << m1++ << endl;
    cout << m1 << endl;
    cout << ++m1 << endl;

    cout << m1 + m2 << endl;
    m1 += m2;
    cout << m1 << endl;
    cout << m3 + m2 << endl;
}
