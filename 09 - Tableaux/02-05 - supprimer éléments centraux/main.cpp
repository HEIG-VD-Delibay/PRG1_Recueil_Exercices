#include <iostream>
#include <vector>

using namespace std;

// TODO DY: inclure to_string code !

int main() {
    for (vector<int> v: {vector<int>{},
                         {1},
                         {1, 2},
                         {1, 2, 3},
                         {1, 2, 3, 4},
                         {1, 2, 3, 4, 5},
                         {1, 2, 3, 4, 5, 6}}) {
        cout << to_string(v) << " -> ";
        supprimer_centre(v);
        cout << to_string(v) << endl;
    }
}
