#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

double retrait(double montantRetrait,
               double &soldeCourant);

void afficher(const string &texte,
              double valeur,
              int precision);

//------------------------------------------------------------
int main() {
    double soldeCourant = 500,
           retraitEffectif;
    retraitEffectif = retrait(300, soldeCourant);
    afficher("Montant retrait effectif = ", retraitEffectif, 1);
    afficher("Solde courant            = ", soldeCourant, 1);

    retraitEffectif = retrait(300, soldeCourant);
    afficher("Montant retrait effectif = ", retraitEffectif, 1);

    afficher("Solde courant            = ", soldeCourant, 1);
    return EXIT_SUCCESS;
}

//------------------------------------------------------------
double retrait(double montantRetrait,
               double &soldeCourant) {
    double retraitEffectif;
    if (soldeCourant > montantRetrait) {
        retraitEffectif = montantRetrait;
        soldeCourant = soldeCourant - montantRetrait;
    }

    else {
        // soldeCourant <= montantRetrait
        retraitEffectif = soldeCourant;
        soldeCourant = 0;
    }

    return retraitEffectif;
}

//------------------------------------------------------------
void afficher(const string &texte, double valeur, int precision) {
    cout << texte << fixed << setprecision(precision) << valeur << endl;
}

//------------------------------------------------------------
// Montant retrait effectif = 300.0
// Solde courant            = 200.0
// Montant retrait effectif = 200.0
// Solde courant            = 0.0
