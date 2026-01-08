#include <algorithm>
#include <iostream>
#include <span>
#include <vector>

using namespace std;

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
bool tab_contient_val(const T &e, span<T> tab) {
    return find(tab.begin(), tab.end(), e) != tab.end();
}

//---------------------------------------------------------
template<typename T>
bool meme_elements(span<T> tab1, span<T> tab2) {

    for (const T &e: tab1)
        if (not tab_contient_val<T>(e, tab2))
            return false;

    for (const T &e: tab2)
        if (not tab_contient_val<T>(e, tab1))
            return false;

    return true;
}

//---------------------------------------------------------
int main() {

    array a{10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    vector v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1, 2};

    cout << span<int>(a) << endl;
    cout << span<int>(v) << endl;

    cout << meme_elements<int>(span<int>(a), span<int>(v));
}
