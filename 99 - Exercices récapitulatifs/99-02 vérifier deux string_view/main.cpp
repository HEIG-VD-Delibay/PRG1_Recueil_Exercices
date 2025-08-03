#include <iostream>
using namespace std;

void tester(string_view a, string_view b) {
    cout << '\"' << a << "\" "
         << (verifier(a, b) ? "" : "in") << "compatible avec "
         << '\"' << b << '\"' << endl;
}

int main() {
    tester("abcdef", "FEDBAC");
    tester("abcdef", "xyz123");
    tester("abcA", "cAba");
}
