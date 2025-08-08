#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <utility>

class Point {
public:
    Point();
    Point(double x, double y);
    Point(const Point &p);
    void setX(double x);
    void setY(double y);
    double getX() const;
    double getY() const;
    void deplacer(double dx, double dy);
    void afficher() const;

private:
    double x, y;
};

// -----------------------------------------------------------------
std::pair<double, double> analyserPoint(const Point &p);
std::ostream &operator<<(std::ostream &cout, const Point &p);
Point operator+(const Point &lhs, const Point &rhs);
Point operator+(const Point &lhs, double rhs);
Point operator+(double rhs, const Point &lhs);
bool operator==(const Point &lhs, const Point &rhs);

// -----------------------------------------------------------------
#endif /* POINT_H */
