#include <iostream>
#include <sstream>
#include <vector>

using namespace std;


// Note: Version optimisée. Une autre solution existe dans l'explication de la solution.
void supprimer_valeur(vector<int> &v, int val) {
    size_t write_idx = 0;
    while (write_idx < v.size() and v[write_idx] != val) {
        ++write_idx;
    }
    for (size_t read_idx = write_idx; read_idx < v.size(); ++read_idx) {
        if (v[read_idx] != val) {
            v[write_idx] = v[read_idx];
            ++write_idx;
        }
    }
    v.resize(write_idx);
}

string to_string(const vector<int> &v) {
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
    for (vector<int> v: {vector<int>{},
                         {2},
                         {1, 2, 2, 2, 3, 1, 2, 4},
                         {2, 3, 4, 3, 2, 1},
                         {2, 2, 2},
                         {5, 4, 3, 2, 1, 2}}) {
        cout << to_string(v) << " -> ";
        supprimer_valeur(v, 2);
        cout << to_string(v) << endl;
    }
}
