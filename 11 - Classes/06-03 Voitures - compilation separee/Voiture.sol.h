#ifndef VOITURE_H
#define VOITURE_H

class Voiture {
public:
    Voiture(unsigned capaciteReservoir, double consommationMoyenne);
    unsigned getCapaciteReservoir() const;
    double getConsommationMoyenne() const;
    double getNbLitresDansReservoir() const;
    double effectuerTrajet(double nbKm);// en valeur de retour : le coût du trajet
    static double getPrixEssence();
    static void setPrixEssence(double prix);

private:
    static double prixEssence;       // en Frs
    const unsigned capaciteReservoir;// en litres
    const double consommationMoyenne;// litres aux 100 km
    double nbLitresDansReservoir;    // nb de litres actuellement dans le réservoir
};

#endif /* VOITURE_H */
