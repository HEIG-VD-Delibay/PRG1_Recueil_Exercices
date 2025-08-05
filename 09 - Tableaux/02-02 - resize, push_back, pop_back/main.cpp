#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

string to_string(const vector<int> &v) {
    stringstream out;
    out << '[';
    for (size_t i = 0; i < v.size(); ++i) {
        if (i)
            out << ", ";
        out << v[i];
    }
    out << ']';
    return out.str();
}

int main() {
    vector<int> v{1, 2, 3, 4, 5, 6};
    cout << "Given    : " << to_string(v) << endl;
    my_push_back(v, 7);// v contient {1, 2, 3, 4, 5, 6, 7}
    cout << "Pushed 7 : " << to_string(v) << endl;
    my_pop_back(v);// v contient {1, 2, 3, 4, 5, 6}
    cout << "Popped   : " << to_string(v) << endl;
    my_pop_back(v);// v contient {1, 2, 3, 4, 5}
    cout << "Popped   : " << to_string(v) << endl;
    my_resize(v, 3);// v contient {1, 2, 3}
    cout << "Resized 3: " << to_string(v) << endl;
    my_resize(v, 5, 1);// v contient {1, 2, 3, 1, 1}
    cout << "Resized 5: " << to_string(v) << endl;
    my_resize(v, 8);// v contient {1, 2, 3, 1, 1, 0, 0, 0}
    cout << "Resized 8: " << to_string(v) << endl;
}
