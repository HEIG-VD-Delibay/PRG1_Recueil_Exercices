#include <iostream>

#include "Point.sol.h"

using namespace std;

int Point::nbPoints = 0;
int Point::prochainId = 1;

Point::Point() : Point(0., 0.) {}

Point::Point(double x, double y, double maxX, double maxY) : x(x), y(y), maxX(maxX), maxY(maxY), id(prochainId) {
    ++prochainId;
    ++nbPoints;
}

Point::~Point() {
    --nbPoints;
}

void Point::setX(double x) {
    this->x = x;
}

void Point::setY(double y) {
    this->y = y;
}

void Point::deplacer(double dx, double dy) {
    if (x + dx <= maxX && y + dy <= maxY) {
        x += dx;
        y += dy;
    }
}

void Point::afficher() const {
    cout << "Point ID = " << id << ", (" << x << "," << y << ")" << ", maxX = " << maxX << ", maxY = " << maxY << endl;
}
