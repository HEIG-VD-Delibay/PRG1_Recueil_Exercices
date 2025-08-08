#include <iostream>

using namespace std;

int main() {
    Point centre;
    centre.setX(0);
    centre.setY(0);
    centre.afficher();

    Point p;
    p.setX(1.2);
    p.setY(2.4);
    p.afficher();

    p.deplacer(0.8, 0.6);
    p.afficher();

    p.setX(5.5);
    p.setY(10.3);
    cout << p.getX() << " -- " << p.getY() << endl;
}
