#include <iostream>
using namespace std;

//------------------------------------------------------------
template<typename T>
class Coord {
public:
    Coord() : Coord(T(), T()) {};
    Coord(T x, T y) : x(x), y(y) {};

    void setCoord(T x, T y);
    T getX() const { return x; }
    T getY() const { return y; }

    void deplacer(T dx, T dy);
    void afficher() const;

private:
    T x;
    T y;
};

//------------------------------------------------------------
int main() {

    const Point<int> origin;

    cout << "p1       : ";
    Point<int> p1("p1"s);
    p1.afficher();
    cout << endl;

    cout << "p2       : ";
    Point<double> p2("p2"s, Coord(1.2, 3.4));
    p2.afficher();
    cout << endl;

    cout << "p3       : ";
    Point<double> p3("p3"s, 1.2, 3.4);
    p3.afficher();
    cout << endl;

    cout << "p3.1     : ";
    p3.setNom("p3.1"s);
    p3.afficher();
    cout << endl;

    cout << "p1(-1, 1): ";
    p1.setCoord(Coord(-1, 1));
    p1.afficher();
    cout << endl;

    cout << "p1->     : ";
    p1.deplacer(-1, 1);
    p1.afficher();
    cout << endl;

    cout << "p1(x)    : ";
    cout << p1.getNom() << " " << p1.getCoord().getX();
}

//------------------------------------------------------------
//   class Coord
//------------------------------------------------------------
template<typename T>
void Coord<T>::setCoord(T x, T y) {
    this->x = x;
    this->y = y;
}

//------------------------------------------------------------
template<typename T>
void Coord<T>::deplacer(T dx, T dy) {
    this->x += dx;
    this->y += dy;
}

//------------------------------------------------------------
template<typename T>
void Coord<T>::afficher() const {
    cout << "(" << this->x << ", " << this->y << ")";
}
