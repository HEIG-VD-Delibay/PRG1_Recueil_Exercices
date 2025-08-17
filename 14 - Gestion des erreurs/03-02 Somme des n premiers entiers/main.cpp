#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

int sommeNPremiersEntiers(int n);// TODO

void test(int n);

int main() {

    test(-1);
    test(0);
    test(1);
    test(65535);
    test(65536);

    return EXIT_SUCCESS;
}

void test(int n) {
    cout << "sommeNPremiersEntiers(" << to_string(n) << ")";
    try {
        cout << " = " << sommeNPremiersEntiers(n) << endl;
    } catch (const exception &e) {
        cout << ": " << e.what() << endl;
    }
}
