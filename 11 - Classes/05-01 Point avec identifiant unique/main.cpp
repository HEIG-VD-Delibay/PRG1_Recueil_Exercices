#include <iostream>

using namespace std;

int main() {

    Point p1(1.2, 2.4);
    p1.afficher();

    cout << "Nombre de points : " << Point::getNbPoints() << endl;
    cout << "-------------------------------------------" << endl;

    {
        Point p2(3., 4.2, 10., 10.);
        p2.afficher();

        cout << "Nombre de points : " << Point::getNbPoints() << endl;
        cout << "-------------------------------------------" << endl;

        p2 = p1;
        p2.afficher();

        cout << "Nombre de points : " << Point::getNbPoints() << endl;
        cout << "-------------------------------------------" << endl;

        Point p3 = p2;
        p3.afficher();

        cout << "Nombre de points : " << Point::getNbPoints() << endl;
        cout << "-------------------------------------------" << endl;
    }

    Point p4(5, 10);
    p4.afficher();

    cout << "Nombre de points : " << Point::getNbPoints() << endl;
    cout << "-------------------------------------------" << endl;
}
