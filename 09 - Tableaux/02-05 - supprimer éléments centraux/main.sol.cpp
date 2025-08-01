#include <iostream>
#include <vector>

using namespace std;

void supprimer_centre(vector<int> &v) {
    if (v.empty())
        return;
    int n = 2 - v.size() % 2;// nombre d'éléments à supprimer
    for (size_t i = 1 + v.size() / 2; i < v.size(); ++i) {
        v[i - n] = v[i];
    }
    v.resize(v.size() - n);
}


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
