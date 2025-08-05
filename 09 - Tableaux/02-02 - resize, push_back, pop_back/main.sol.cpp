#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

void my_resize(vector<int> &v, size_t n, int value = int()) {
    while (v.size() < n)
        v.push_back(value);
    while (v.size() > n)
        v.pop_back();
}

void my_push_back(vector<int> &v, int value) {
    v.resize(v.size() + 1, value);
}

void my_pop_back(vector<int> &v) {
    v.resize(v.size() - 1);
}

// TODO: check to_string impl ??
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
