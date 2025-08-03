#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v{6, 3, 4, 5, 4, 3, 1, 2, 2, 3, 4, 3, 7};

    cout << "Plus long sequence croissante (1): ";
    auto r1 = plus_long_sequence_croissante(v.begin(), v.end());
    for (auto it = r1.first; it != r1.second; ++it)
        cout << *it << ' ';

    cout << "\nPlus long sequence croissante (2): ";
    auto r2 = plus_long_sequence_croissante(v.cbegin(), v.cend(), less<int>{});
    for (auto it = r2.first; it != r2.second; ++it)
        cout << *it << ' ';

    cout << "\nPlus long sequence décroissante : ";
    auto r3 = plus_long_sequence_croissante(v.begin(), v.end(), greater<int>{});
    for (auto it = r3.first; it != r3.second; ++it)
        cout << *it << ' ';

    cout << endl;
}
