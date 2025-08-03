#include <array>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    Vec3 v1{};
    cout << "v1 = " << v1 << endl;

    v1[2] = 2;
    cout << "v1 = " << v1 << endl;

    array a{1., 3., 2.};
    const Vec3 v2(a.begin(), a.end());
    cout << "v2 = " << v2 << endl;

    for (size_t i = 0; i < 3; ++i)
        cout << "v2[" << i << "] = " << v2[i] << ((i < 2) ? ", " : "\n");

    vector b{4., 2., 5.};
    Vec3 v3(b.begin(), b.end());
    cout << "v3 = " << v3 << endl;

    Vec3 v4 = v2 + v3;
    cout << "v4 = " << v4 << endl;

    v4 += v2;
    cout << "v4 = " << v4 << endl;

    Vec3 x = Vec3::axis(0);
    cout << "x = " << x << endl;
    Vec3 y = Vec3::axis(1);
    cout << "y = " << y << endl;
    Vec3 z = Vec3::axis(2);
    cout << "z = " << z << endl;
}
