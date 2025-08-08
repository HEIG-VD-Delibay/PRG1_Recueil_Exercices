#include <iostream>

using namespace std;

int main() {
    Point centre;
    centre.afficher();

    Point p(1.2, 2.4);
    p.afficher();

    p.deplacer(0.8, 0.6);
    p.afficher();

    p.setX(5.5);
    p.setY(10.3);
    cout << p.getX() << " -- " << p.getY() << endl;
}
