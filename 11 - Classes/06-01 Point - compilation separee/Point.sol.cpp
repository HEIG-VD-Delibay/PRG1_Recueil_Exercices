#include <iomanip>
#include <iostream>
#include <utility>

#include "Point.sol.h"

using namespace std;

Point::Point() : Point(0., 0.) {}

Point::Point(double x, double y) : x(x), y(y) {}

Point::Point(const Point &p) : Point(p.x, p.y) {}

void Point::setX(double x) {
    this->x = x;
}

void Point::setY(double y) {
    this->y = y;
}

double Point::getX() const {
    return this->x;
}

double Point::getY() const {
    return this->y;
}

void Point::deplacer(double dx, double dy) {
    x += dx;
    y += dy;
}

void Point::afficher() const {
    cout << "(" << x << "," << y << ")" << endl;
}

// -----------------------------------------------------------------
pair<double, double> analyserPoint(const Point &p) {
    return {p.getX(), p.getY()};
}

ostream &operator<<(ostream &cout, const Point &p) {
    return cout << fixed << setprecision(1)
                << "(" << p.getX() << ","
                << p.getY() << ")";
}

Point operator+(double rhs, const Point &lhs) {
    return lhs + rhs;
}

Point operator+(const Point &lhs, const Point &rhs) {
    return Point(lhs.getX() + rhs.getX(), lhs.getY() + rhs.getY());
}

Point operator+(const Point &lhs, double rhs) {
    return Point(lhs.getX() + rhs, lhs.getY() + rhs);
}

bool operator==(const Point &lhs, const Point &rhs) {
    return lhs.getX() == rhs.getX() && lhs.getY() == rhs.getY();
}
