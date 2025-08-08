#include <iostream>
using namespace std;

int main() {
    cout << "origine  : ";
    const Coord<int> origin;
    origin.afficher();
    cout << endl;

    cout << "p1       : ";
    Coord<int> p1;
    p1.setCoord(1, 2);
    p1.afficher();
    cout << endl;

    cout << "p2       : ";
    Coord<double> p2(3, 4);
    p2.afficher();
    cout << endl;

    cout << "p2->     : ";
    p2.deplacer(1, 1);// conversion int => double
    p2.afficher();
    cout << endl;

    Coord<string> p3("x", "y");
    p3.afficher();
    cout << endl;
}
