#include <array>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

bool est_strictement_croissant(span<const int> s) {
    for (size_t i = 1; i < s.size(); ++i)
        // boucle sur toutes les paires d'indices (i-1, i)
        if (s[i] <= s[i - 1])
            return false;
    return true;
}

template<typename Tab>
string to_string(const Tab &v) {
    stringstream out;
    out << '[';
    for (size_t i = 0; i < v.size(); ++i) {
        if (i)
            out << ", ";
        out << v[i];
    }
    out << ']';
    return out.str();
}

int main() {
    for (vector<int> const &v:
         {vector<int>{1, 2, 3, 4, 6, 9},
          {1, 2, 3, 4, 6, 5},
          {1, 2, 3, 3, 4, 4},
          {1},
          {}})
        cout << to_string(v)
             << (est_strictement_croissant(v) ? " est" : " n'est pas")
             << " strictement croissant" << endl;

    array a{2, 3, 5, 7, 11, 13};
    cout << to_string(a)
         << (est_strictement_croissant(a) ? " est" : " n'est pas")
         << " strictement croissant" << endl;
}
