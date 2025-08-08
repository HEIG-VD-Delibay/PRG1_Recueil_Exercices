#include <array>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

enum class Chiffre { ZERO,
                     UN,
                     DEUX,
                     TROIS,
                     QUATRE,
                     CINQ,
                     SIX,
                     SEPT,
                     HUIT,
                     NEUF };
// nbreToEnums

int main(int argc, char *argv[]) {
    if (argc == 2) {
        int given = std::stoi(argv[1]);
        cout << nbreToEnums(given);
    } else {
        cerr << "Missing argument 1" << endl;
    }
    return 0;
}
