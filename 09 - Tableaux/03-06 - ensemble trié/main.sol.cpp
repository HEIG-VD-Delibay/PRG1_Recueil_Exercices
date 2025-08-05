#include <array>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

bool inclut(span<const int> s, int val) {
    for (int e: s)
        if (e == val) return true;
    return false;
}

void inserer_dernier_element(span<int> s) {
    if (s.empty()) return;

    int e = s.back();
    size_t i = s.size() - 1;
    while (i > 0 and e < s[i - 1]) {
        s[i] = s[i - 1];
        --i;
    }
    s[i] = e;
}

vector<int> ensemble(span<const int> s) {
    vector<int> v;
    for (int e: s) {
        if (not inclut(v, e)) {
            v.push_back(e);
            inserer_dernier_element(v);
        }
    }
    return v;
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
         {vector<int>{1, 2, 4, 1, 2, 5, 3, 6, 2, 1},
          {1, 1, 1, 1, 1, 1},
          {1, 2, 3, 4},
          {1},
          {}})
        cout << to_string(v) << " -> " << to_string(ensemble(v)) << endl;

    array a{1, 3, 2, 4, 2, 1, 3};
    cout << to_string(a) << " -> " << to_string(ensemble(a)) << endl;
}
