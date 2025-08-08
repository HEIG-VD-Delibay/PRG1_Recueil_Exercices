#include <array>
#include <iostream>
#include <span>
#include <vector>

using namespace std;

template<typename T>
ostream &operator<<(ostream &os, span<T> s) {
    os << "[";
    for (size_t i = 0; i < s.size(); ++i) {
        if (i) os << ", ";
        os << s[i];
    }
    return os << "]";
}

// merge

int main() {

    vector v{11, 12, 13};
    array a{21, 22, 23, 24, 25};

    cout << "vector   : " << span<int>(v) << endl;
    cout << "array    : " << span<int>(a) << endl;

    vector r = merge<int>(v.begin(), v.end(),
                          a.begin(), a.end());

    cout << "resultat : " << span<int>(r) << endl;
}
