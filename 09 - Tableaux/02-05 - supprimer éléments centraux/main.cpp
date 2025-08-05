#include <iostream>
#include <vector>

using namespace std;

// supprimer_centre

string to_string(span<const int> v) {
    string result = "[";
    for (size_t i = 0; i < v.size(); ++i) {
        if (i)
            result += ", ";
        result += to_string(v[i]);
    }
    return result += "]";
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
