#include <iostream>
using namespace std;

// Robot

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
