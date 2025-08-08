#include <cstdlib>
#include <iostream>
using namespace std;

enum class Dir { GAUCHE = -1,
                 DROITE = 1 };// +1 = vers la droite, -1 = vers la gauche

class Robot {
public:
    Robot(int positionInitiale = 0);
    void faireDemiTour();
    void deplacer(int nbUnites = 1);
    int getPosition() const;

private:
    Dir direction;
    int position;// la position courante du robot
};

Robot::Robot(int positionInitiale)
    : direction(Dir::DROITE), position(positionInitiale) {
}

void Robot::faireDemiTour() {
    direction == Dir::GAUCHE ? direction = Dir::DROITE : direction = Dir::GAUCHE;
}

void Robot::deplacer(int nbUnites) {
    if (nbUnites > 0)
        position += int(direction) * nbUnites;
}

int Robot::getPosition() const {
    return position;
}

int main() {
    Robot r1, r2(10);
    cout << "position courante de r2: " << r2.getPosition() << endl;
    r1.deplacer();
    cout << "position courante de r1: " << r1.getPosition() << endl;
    r1.deplacer(-1);
    cout << "position courante de r1: " << r1.getPosition() << endl;
    r1.deplacer(2);
    cout << "position courante de r1: " << r1.getPosition() << endl;
    r1.faireDemiTour();
    r1.deplacer(4);
    cout << "position courante de r1: " << r1.getPosition() << endl;
    return EXIT_SUCCESS;
}
