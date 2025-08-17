#include <cstdlib>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>
using namespace std;

using ullong = unsigned long long;

int sommeNPremiersEntiers(int n);
void test(int n);

int main() {

    test(-1);
    test(0);
    test(1);
    test(65535);
    test(65536);

    return EXIT_SUCCESS;
}

int sommeNPremiersEntiers(int n) {
    if (n < 0)
        throw invalid_argument("Argument non valide: n doit etre >= 0");
    const ullong SOMME = (ullong) n * ((ullong) n + 1) / 2;
    if (SOMME > numeric_limits<int>::max())
        throw overflow_error("Un debordement est survenu dans les calculs");
    return (int) SOMME;
}

void test(int n) {
    cout << "sommeNPremiersEntiers(" << to_string(n) << ")";
    try {
        cout << " = " << sommeNPremiersEntiers(n) << endl;
    } catch (const exception &e) {
        cout << ": " << e.what() << endl;
    }
}

// sommeNPremiersEntiers(-1): Argument non valide: n doit etre >= 0
// sommeNPremiersEntiers(0) = 0
// sommeNPremiersEntiers(1) = 1
// sommeNPremiersEntiers(65535) = 2147450880
// sommeNPremiersEntiers(65536): Un debordement est survenu dans les calculs
