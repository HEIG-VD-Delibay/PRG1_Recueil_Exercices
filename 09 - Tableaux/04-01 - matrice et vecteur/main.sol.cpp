#include <array>
#include <iostream>
#include <sstream>

using namespace std;

using Matrice3x3 = array<array<double, 3>, 3>;
using Vec3 = array<double, 3>;

string to_string(Vec3 const &v) {
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

string to_string(Matrice3x3 const &v) {
    stringstream out;
    out << '[';
    for (size_t i = 0; i < v.size(); ++i) {
        if (i)
            out << "\n ";
        out << to_string(v[i]);
    }
    out << ']';
    return out.str();
}

Vec3 produit(Matrice3x3 const &m, Vec3 const &v) {
    Vec3 w{};
    for (size_t i = 0; i < m.size(); ++i) {
        for (size_t j = 0; j < m.size(); ++j) {
            w[i] += m[i][j] * v[j];
        }
    }
    return w;
}

int main() {
    Matrice3x3 m = {1, 1, 0, 0, 2, 0, 0, 0, 1};
    Vec3 v = {1, 2, 3};
    Vec3 w = produit(m, v);

    cout << to_string(m) << " * "
         << to_string(v) << " = "
         << to_string(w) << endl;
}
