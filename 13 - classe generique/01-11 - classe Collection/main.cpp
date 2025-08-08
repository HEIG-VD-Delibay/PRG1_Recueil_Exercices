#include <cstdlib>
#include <iostream>

#include <list>
#include <vector>

#include "Collection.h"

using namespace std;

int main() {

    // vector<int>
    Collection<int, std::vector> s1;
    for (int i: {0, 1, 2, 3, 4, 5}) {
        s1.add(i);
    }
    cout << s1 << endl;
    s1.remove(2);
    cout << s1 << endl;
    s1.clear();

    // list<string>
    Collection<string, std::list> s2;
    for (const string &s: {"chien"s, "chat"s, "souris"s}) {
        s2.add(s);
    }
    cout << string(s2) << endl;
    cout << endl;

    cout << "taille de s2 : " << s2.size() << endl;
    cout << "s2 " << (s2.empty() ? "est" : "n'est pas") << " vide" << endl;

    return EXIT_SUCCESS;
}
