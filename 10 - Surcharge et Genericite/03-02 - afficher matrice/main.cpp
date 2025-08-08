#include <iostream>
#include <vector>

using namespace std;
template<typename T>
using Ligne = vector<T>;

template<typename T>
using Matrice = vector<Ligne<T>>;

// todo

int main(int argc, char *argv[]) {

    Matrice<int> m{{0},
                   {1, 2},
                   {3, 4, 5},
                   {6, 7, 8, 9}};
    cout << m << endl;
    return 0;
}
