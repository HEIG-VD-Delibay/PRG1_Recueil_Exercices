//----------------------------------------------
// A NOTER
// - pas de using namespace std
// - pas de #using <iostream>
//----------------------------------------------

#ifndef DATE_H
#define DATE_H

#include <cstdint>

using Jour  = uint8_t;
using Mois  = uint8_t;
using Annee = uint16_t;

struct Date {
   Jour  jour;
   Mois  mois;
   Annee annee;
};

void afficher_date(const Date& d);

#endif //DATE_H
