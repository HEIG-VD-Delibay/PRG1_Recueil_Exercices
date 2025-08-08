#include <algorithm>
#include <iostream>
#include <span>
#include <vector>

using namespace std;

// Solution 1 présentée ici

//---------------------------------------------------------
template<typename T>
ostream &operator<<(ostream &os, span<T> s) {
    os << "[";
    for (size_t i = 0; i < s.size(); ++i) {
        if (i) os << ", ";
        os << s[i];
    }
    return os << "]";
}

//---------------------------------------------------------
template<typename T>
struct entre {
    const T &min;
    const T &max;
    bool operator()(const T &e) { return e >= min and e <= max; }
};

//---------------------------------------------------------
int main() {

    vector v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << "vecteur    : " << span(v) << endl;
    cout << "intervalle : [3, 6]" << endl;
    cout << "résultat   : " << count_if(v.begin(), v.end(), entre<int>{3, 6}) << endl;
}
