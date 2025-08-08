#include "Voiture.sol.h"

double Voiture::prixEssence = 1.7;

Voiture::Voiture(unsigned capaciteReservoir, double consommationMoyenne)
    : capaciteReservoir(capaciteReservoir),
      consommationMoyenne(consommationMoyenne),
      nbLitresDansReservoir(capaciteReservoir) {
}

unsigned Voiture::getCapaciteReservoir() const {
    return capaciteReservoir;
}

double Voiture::getConsommationMoyenne() const {
    return consommationMoyenne;
}

double Voiture::getNbLitresDansReservoir() const {
    return nbLitresDansReservoir;
}

double Voiture::effectuerTrajet(double nbKm) {
    const double CONSOMMATION = nbKm * consommationMoyenne / 100;
    nbLitresDansReservoir -= CONSOMMATION;
    while (nbLitresDansReservoir <= 0)
        nbLitresDansReservoir += capaciteReservoir;
    return CONSOMMATION * prixEssence;
}

double Voiture::getPrixEssence() {
    return prixEssence;
}

void Voiture::setPrixEssence(double prix) {
    prixEssence = prix;
}
