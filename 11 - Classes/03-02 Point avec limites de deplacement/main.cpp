#include <iostream>

using namespace std;

int main() {
    Point p1(1.2, 2.4);
    cout << "p1";
    p1.afficher();
    p1.deplacer(1., 3.);
    cout << "p1";
    p1.afficher();
    p1.setX(4.);
    cout << "p1";
    p1.afficher();
    p1.setY(7.);
    cout << "p1";
    p1.afficher();

    Point p2(3., 4.2, 10., 10.);
    cout << "p2";
    p2.afficher();
    p2.deplacer(15, 2);
    cout << "p2";
    p2.afficher();
    p2.deplacer(3, 2);
    cout << "p2";
    p2.afficher();
    p2.setX(-3);
    cout << "p2";
    p2.afficher();
    p2.setY(12);
    cout << "p2";
    p2.afficher();
}
