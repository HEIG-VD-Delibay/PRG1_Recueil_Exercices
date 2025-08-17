//----------------------------------------------
// A NOTER
// - using namespace std possible
// - #include <iostream> ici et non dans le .h
// - cast (int)d.jour et (int)d.mois sinon un car est affiché
//----------------------------------------------

#include "date.sol.h"
#include <iostream>

void afficher_date(const Date &d) {
    std::cout << (int) d.jour << '.'
              << (int) d.mois << '.'
              << d.annee;
}
