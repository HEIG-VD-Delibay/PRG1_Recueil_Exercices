#include <array>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    array carnet{Personne{"Jean"s, "Veuxplus"s, Date{7, 4, 1975}},
                 Personne{"Alain"s, "Verse"s, Date{21, 12, 2018}},
                 Personne{"Justin"s, "Ptipeu"s, Date{1, 8, 2023}},
                 Personne{"Rémi"s, "Fasol"s, Date{17, 5, 1957}}};

    cout << carnet << endl;
    return 0;
}
