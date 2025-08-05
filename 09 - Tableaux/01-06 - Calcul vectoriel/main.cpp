#include <array>
#include <iostream>
using namespace std;

using Vec3d = array<double, 3>;

// to_string
// produit
// produit_scalaire
// produit_vectoriel

int main() {
    Vec3d a{1., 2., 3.};
    Vec3d b{2., 4., 3.};
    cout << "a = " << to_string(a) << endl
         << "b = " << to_string(b) << endl;

    Vec3d c = produit(a, 2.);
    cout << "c = a*2 = " << to_string(c) << endl;

    cout << "a.b = " << produit_scalaire(a, b)
         << ", a.c = " << produit_scalaire(a, c)
         << ", b.c = " << produit_scalaire(b, c) << endl;

    Vec3d d = produit_vectoriel(a, b);
    cout << "d = a^b = " << to_string(d) << endl;
    cout << "a.d = " << produit_scalaire(a, d)
         << ", b.d = " << produit_scalaire(b, d) << endl;

    Vec3d e = produit_vectoriel(a, a);
    cout << "e = a^a = " << to_string(e) << endl;
}
