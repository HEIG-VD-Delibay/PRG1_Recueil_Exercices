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

vector<int> ensemble(span<const int> s) {
    vector<int> v;
    for (int e: s) {
        if (not inclut(v, e))
            v.push_back(e);
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
