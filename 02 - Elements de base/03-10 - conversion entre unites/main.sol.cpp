#include <cstdlib>
#include <iostream>
using namespace std;

int main() {

    const double metres_en_miles = 6.213711922e-4;
    const double metres_en_ft = 3.280839895;
    const double metres_en_inch = 39.37007874;

    // Saisie utilisateur
    int nb_metres;
    cout << "Entrez le nombre de metres a convertir (entier > 0) : ";
    cin >> nb_metres;

    cout << nb_metres << " [m]" << endl
         << "= " << nb_metres * metres_en_miles << " [mile]" << endl
         << "= " << nb_metres * metres_en_ft << " [ft]" << endl
         << "= " << nb_metres * metres_en_inch << " [inch]" << endl;

    return EXIT_SUCCESS;
}
