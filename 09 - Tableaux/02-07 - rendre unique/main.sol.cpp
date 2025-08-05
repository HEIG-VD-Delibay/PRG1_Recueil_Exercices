#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

void rendre_unique(vector<int> &v) {
    if (v.empty()) return;

    size_t write_idx = 0;
    for (size_t read_idx = 1; read_idx < v.size(); ++read_idx) {
        if (v[read_idx] != v[write_idx]) {
            v[++write_idx] = v[read_idx];
        }
    }
    v.resize(write_idx + 1);
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
                         {2, 3, 3, 2, 2, 1},
                         {2, 2, 2},
                         {5, 4, 4, 3, 2, 2, 2, 3}}) {
        cout << to_string(v) << " -> ";
        rendre_unique(v);
        cout << to_string(v) << endl;
    }
}
