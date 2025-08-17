//----------------------------------------------
// A NOTER
// - using namespace std possible
// - #using <iostream> nécessaire
// - pas de #include <string>, déjà dans le .h
//----------------------------------------------

#include "personne.sol.h"
#include <iostream>

void afficher_personne(const Personne &p) {
    std::cout << "Nom          : " << p.nom << std::endl
              << "Adresse      : " << p.adresse << std::endl
              << "Anniversaire : ";
    afficher_date(p.anniversaire);
}
