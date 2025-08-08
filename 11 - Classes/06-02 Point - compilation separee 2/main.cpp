#include <iostream>

using namespace std;

nobuild "solution de l'exercice '03-02 Point avec limites de deplacement' à refactoriser en compilation séparée";

class Point {
public:
    // constructeurs
    Point();
    Point(double x, double y, double maxX = 100., double maxY = 100.);

    // fonctions membres
    void deplacer(double dx, double dy);
    void afficher() const;

    // modificateurs
    void setX(double x);
    void setY(double y);

private:
    double x, y;
    double maxX, maxY;// pas besoin de const. L'absence de modificateurs suffit

    bool x_valide(double x) const;
    bool y_valide(double y) const;
};

// -----------------------------------------------------------------

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

// -----------------------------------------------------------------
Point::Point() : Point(0., 0.) {}

Point::Point(double x, double y, double maxX, double maxY) : x(x), y(y), maxX(max(x, maxX)), maxY(max(y, maxY)) {}

bool Point::x_valide(double x) const {
    return x >= 0 and x <= maxX;
}

bool Point::y_valide(double y) const {
    return y >= 0 and y <= maxY;
}

void Point::setX(double x) {
    if (x_valide(x))
        this->x = x;
}

void Point::setY(double y) {
    if (y_valide(y))
        this->y = y;
}

void Point::deplacer(double dx, double dy) {
    if (x_valide(x + dx) and y_valide(y + dy)) {
        x += dx;
        y += dy;
    }
}

void Point::afficher() const {
    cout << "(" << x << "," << y << ")" << ", contraintes: [0," << maxX << "]x[0," << maxY << "]\n";
}
// -----------------------------------------------------------------
