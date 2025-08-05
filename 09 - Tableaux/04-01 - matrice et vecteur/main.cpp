#include <array>
#include <iostream>
#include <sstream>

using namespace std;

// alias de type
// to_string Vec3
// to_string Matrice3x3

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
    Matrice3x3 m = {1, 1, 0, 0, 2, 0, 0, 0, 1};
    Vec3 v = {1, 2, 3};
    Vec3 w = produit(m, v);

    cout << to_string(m) << " * "
         << to_string(v) << " = "
         << to_string(w) << endl;
}
