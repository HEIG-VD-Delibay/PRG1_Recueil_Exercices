#include <cstdlib>
#include <iostream>

using namespace std;
int main() {
    f;
    g(1, 2.0);
    h(64, 65);

    return EXIT_SUCCESS;
}

void f {
    cout << "Appel de f\n";
}

//------------------------------------------------------------
void g(int i, j) {
    cout << "Appel de g avec i = " << i << " et j = " << j << "\n";
}

//------------------------------------------------------------
void h(int i; char c) {
    cout << "Appel de h avec i = " << i << " et c = '" << c << "'\n";
}
