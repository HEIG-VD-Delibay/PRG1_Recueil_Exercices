#include <array>
#include <cstdint>
#include <iostream>

using namespace std;
struct Date {
    uint8_t jour;
    uint8_t mois;
    uint16_t annee;
};

struct Personne {
    string prenom;
    string nom;
    Date date;
};

ostream &operator<<(ostream &os, const Date &d) {
    os << (int) d.jour << "." << (int) d.mois << "." << d.annee;
    // os << +d.jour << "." << +d.mois << "." << d.annee;
    return os;
}

ostream &operator<<(ostream &os, const Personne &p) {
    os << "prenom : " << p.prenom << endl;
    os << "nom    : " << p.nom << endl;
    os << "date   : " << p.date << endl;
    return os;
}

template<typename T, size_t taille>
ostream &operator<<(ostream &os, const array<T, taille> tab) {
    for (const T &t: tab)
        os << t << endl;
    return os;
}


int main(int argc, char *argv[]) {
    array carnet{Personne{"Jean"s, "Veuxplus"s, Date{7, 4, 1975}},
                 Personne{"Alain"s, "Verse"s, Date{21, 12, 2018}},
                 Personne{"Justin"s, "Ptipeu"s, Date{1, 8, 2023}},
                 Personne{"Rémi"s, "Fasol"s, Date{17, 5, 1957}}};

    cout << carnet << endl;
    return 0;
}
