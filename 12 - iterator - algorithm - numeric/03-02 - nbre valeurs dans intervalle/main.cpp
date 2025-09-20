#include <iostream>
#include <vector>

using namespace std;

// TODO okay ?
template<typename T>
ostream &operator<<(ostream &os, span<T> s) {
    os << "[";
    for (size_t i = 0; i < s.size(); ++i) {
        if (i) os << ", ";
        os << s[i];
    }
    return os << "]";
}

int main(int argc, char *argv[]) {
    vector v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << "vecteur    : " << span(v) << endl;
    cout << "intervalle : [3, 6]" << endl;
    cout << "résultat   : " << ? ? << endl;
    return 0;
}
