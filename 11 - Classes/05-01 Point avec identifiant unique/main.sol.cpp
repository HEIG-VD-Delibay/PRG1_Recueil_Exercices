#include <iostream>

using namespace std;

class Point {
public:
    Point();
    Point(double x, double y, double maxX = 100., double maxY = 100.);
    ~Point();

    Point(const Point &other);
    Point &operator=(const Point &other);

    void setX(double x);
    void setY(double y);

    static int getNbPoints() { return nbPoints; }

    void deplacer(double dx, double dy);
    void afficher() const;

private:
    double x, y;
    double maxX, maxY;
    const int id;// attention, avec id const, il faut
    // écrire constructeur de copie et affectation par
    // copie explicitement
    static int prochainId;
    static int nbPoints;

    bool x_valide(double x) const;
    bool y_valide(double y) const;
};

// -----------------------------------------------------------------

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

// -----------------------------------------------------------------
int Point::nbPoints = 0;
int Point::prochainId = 1;

Point::Point() : Point(0., 0.) {}

Point::Point(double x, double y, double maxX, double maxY)
    : x(x), y(y), maxX(maxX), maxY(maxY), id(prochainId) {
    ++prochainId;
    ++nbPoints;
}

Point::~Point() {
    --nbPoints;
}

Point::Point(const Point &other)
    : Point(other.x, other.y, other.maxX, other.maxY) {
    // other.id n'est pas copié. Le constructeur appelé en génère un nouveau
}

Point &Point::operator=(const Point &other) {
    if (&other == this)
        return *this;
    x = other.x;
    y = other.y;
    maxX = other.maxX;
    maxY = other.maxY;
    // other.id n'est pas copié. Il conserve sa valeur précédente
    return *this;
}

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
    cout << "Point ID = " << id << ", (" << x << "," << y << ")" << ", contraintes: [0," << maxX << "]x[0," << maxY << "]\n";
}
// -----------------------------------------------------------------
