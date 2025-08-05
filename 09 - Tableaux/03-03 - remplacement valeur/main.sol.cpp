#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

void remplacer_valeurs_paires(span<int> s, int val) {
    for (int &e: s)
        if (e % 2 == 0)
            e = val;
}

string to_string(span<const int> v) {
    string result = "[";
    for (size_t i = 0; i < v.size(); ++i) {
        if (i)
            result += ", ";
        result += to_string(v[i]);
    }
    return result += "]";
}

int main() {
    vector v{1, 2, 3, 4, 3, 6, 4, 1, 2};
    cout << to_string(v) << " -> ";
    remplacer_valeurs_paires(v, 0);
    cout << to_string(v) << endl;

    vector a{3, 4, 5, 6, 2, 4, 3};
    cout << to_string(a) << " -> ";
    remplacer_valeurs_paires(a, -1);
    cout << to_string(a) << endl;
}
