#include <cstdlib>
#include <iomanip>
#include <iostream>

#include "Voiture.h"

using namespace std;

/*
* Ces trois fonctions sont auxiliares dans le main, 
* la fonction afficherVoiture pourrait eventuellement etre definie dans Voiture.h et Voiture.cpp
*/

void afficherPrixEssence(double prix) {
    cout << fixed << setprecision(2)
         << "Prix de l'essence : " << prix << " Frs"
         << endl
         << endl
         << defaultfloat;
}

void afficherVoiture(const Voiture &v) {
    cout << "Capacite du reservoir [l]      : " << v.getCapaciteReservoir() << endl
         << fixed << setprecision(1)
         << "Consommation moyenne [l/100km] : " << v.getConsommationMoyenne() << endl
         << "Nb litres restants             : " << v.getNbLitresDansReservoir()
         << endl
         << endl
         << defaultfloat;
}

void afficherCoutTrajet(double montant) {
    cout << fixed << setprecision(2)
         << "Cout du trajet : " << montant << " Frs"
         << endl
         << endl
         << defaultfloat;
}

int main() {

    afficherPrixEssence(Voiture::getPrixEssence());

    Voiture::setPrixEssence(1.95);
    afficherPrixEssence(Voiture::getPrixEssence());

    Voiture v(52, 6.7);

    afficherVoiture(v);
    afficherCoutTrajet(v.effectuerTrajet(1000));
    afficherVoiture(v);
    afficherCoutTrajet(v.effectuerTrajet(200));
    afficherVoiture(v);

    return EXIT_SUCCESS;
}
