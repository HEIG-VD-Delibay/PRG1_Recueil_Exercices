#include <iostream>
#include <vector>

using namespace std;

// vect_iter_val

int main() {

    vector v{1, 2, 3, 2, 4, 2, 2, 6, 2};

    using it_int = vector<int>::const_iterator;

    cout << "vecteur d'entiers     : " << span(v) << endl;
    vector vect_int_ref = vect_iter_val<int, it_int>(v, 2);
    cout << "vecteur d'iterateurs  : ";
    afficher_vect_iter(vect_int_ref);
}
