//----------------------------------------------
// A NOTER
// - pas de using namespace std
// - pas de #using <iostream>
// - #include <string> nécessaire (paramètre)
// - #include "date.h" nécessaire (paramètre)
//----------------------------------------------

#ifndef PERSONNE_H
#define PERSONNE_H

#include "date.sol.h"
#include <string>

struct Personne {
    std::string nom;
    std::string adresse;
    Date anniversaire;
};

void afficher_personne(const Personne &p);


#endif//PERSONNE_H
