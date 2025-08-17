#include <cstdlib>
#include <iostream>

#include "date.sol.h"
#include "personne.sol.h"

using namespace std;
int main() {

    Date uneDate = {30, 10, 2023};
    cout << "une date     : ";
    afficher_date(uneDate);
    cout << endl
         << endl;

    Personne anna = {"Anna", "Yverdon", uneDate};
    afficher_personne(anna);

    cout << endl;

    return EXIT_SUCCESS;
}
