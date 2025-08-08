#include <array>
#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector v{11, 12, 13};
    array a{21, 22, 23, 24, 25};

    cout << "vector   : " << span<int>(v) << endl;
    cout << "array    : " << span<int>(a) << endl;

    vector r = concat_tab<int>(v.begin(), v.end(),
                               a.begin(), a.end());

    cout << "resultat : " << span<int>(r) << endl;
}
