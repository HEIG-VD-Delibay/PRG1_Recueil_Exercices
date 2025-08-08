#include <array>
#include <iostream>
#include <span>
#include <vector>

using namespace std;


// Solution 2 présentée ici

template<typename T>
ostream &operator<<(ostream &os, span<T> s) {
    os << "[";
    for (size_t i = 0; i < s.size(); ++i) {
        if (i) os << ", ";
        os << s[i];
    }
    return os << "]";
}

template<typename T, typename Iterator1, typename Iterator2>
vector<T> concat_tab(Iterator1 first1, Iterator1 last1,
                     Iterator2 first2, Iterator2 last2) {
    vector<T> v;
    v.reserve(distance(first1, last1) +
              distance(first2, last2));
    v.insert(v.end(), first1, last1);
    v.insert(v.end(), first2, last2);
    return v;
}

int main() {

    vector v{11, 12, 13};
    array a{21, 22, 23, 24, 25};

    cout << "vector   : " << span<int>(v) << endl;
    cout << "array    : " << span<int>(a) << endl;

    vector r = concat_tab<int>(v.begin(), v.end(),
                               a.begin(), a.end());

    cout << "resultat : " << span<int>(r) << endl;
}
