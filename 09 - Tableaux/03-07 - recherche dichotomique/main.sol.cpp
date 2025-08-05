#include <iostream>
#include <span>
#include <vector>

using namespace std;

string to_string(span<const int> v) {
    string result = "[";
    for (size_t i = 0; i < v.size(); ++i) {
        if (i)
            result += ", ";
        result += to_string(v[i]);
    }
    return result += "]";
}

bool recherche(span<const int> s, int e) {
    if (s.empty())
        return false;
    size_t mid = s.size() / 2;
    if (e < s[mid])
        return recherche(s.first(mid), e);
    else if (e > s[mid])
        return recherche(s.last(s.size() - mid - 1), e);
    else// e == s[mid]
        return true;
}

int main() {
    for (vector<int> const &v:
         {vector<int>{1, 2, 3, 5, 7, 11, 13, 17},
          {1, 3, 5, 7, 9, 11, 13, 15, 17},
          {2, 4, 6, 8, 10, 12, 14, 16, 18},
          {5, 10, 15, 20},
          {11},
          {1},
          {}}) {
        for (int e: {3, 11, 15}) {
            cout << to_string(v)
                 << (recherche(v, e) ? " contient " : " ne contient pas ")
                 << e << endl;
        }
    }
}
