#include <iostream>
#include <vector>
using namespace std;

using Ligne = vector<char>;
using Matrice = vector<Ligne>;

Matrice creer(size_t t = 26) {
    Matrice m;
    m.reserve(t);
    for (size_t i = 0; i < t; ++i) {
        m.push_back(Ligne());
        m.back().reserve(t - i);
        for (size_t j = 0; i + j < t; ++j) {
            m.back().push_back(static_cast<char>('a' + j));
        }
    }
    return m;
}

void afficher(Matrice const &m) {
    for (Ligne const &ligne: m) {
        for (char c: ligne)
            cout << c;
        cout << endl;
    }
}

int main() {
    Matrice m = creer();
    afficher(m);
}
