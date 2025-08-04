#include <iostream>
#include <string>
#include <utility>

using namespace std;

// Ecrivez ici la fonction remplacer_occurences

int main() {
    string texte{"Les sanglots longs de violons de l'automne "
                 "bercent mon coeur d'une langueur monotone"};
    cout << texte << endl;
    for (auto p: {pair<string, string>{"on", "ON"},
                  {"on", "o"},
                  {"on", "oin"},
                  {"o", "ooo"}}) {
        cout << remplacer_occurences(texte, p.first, p.second) << endl;
    }
}
