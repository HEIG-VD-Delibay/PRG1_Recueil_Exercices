#ifndef POINT_H
#define POINT_H

class Point {
public:
    Point();
    Point(double x, double y, double maxX = 100., double maxY = 100.);
    ~Point();

    void setX(double x);
    void setY(double y);

    double getX() const { return x; }
    double getY() const { return y; }
    double getMaxX() const { return maxX; }
    double getMaxY() const { return maxY; }
    double getPointId() const { return id; }
    static double getNbPoints() { return nbPoints; }

    void deplacer(double dx, double dy);
    void afficher() const;

private:
    double x, y;
    double maxX, maxY;
    int id;
    static int prochainId;
    static int nbPoints;
};
#endif /* POINT_H */
