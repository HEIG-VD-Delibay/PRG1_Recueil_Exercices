
#include <iostream>
#include <string>
#include <utility>

using namespace std;

string remplacer_occurences(string_view texte, string_view mot, string_view alt) {
    if (mot.empty())
        return string(texte);

    string r;
    size_t pos = 0;
    while (true) {
        size_t nxt = texte.find(mot, pos);
        r += texte.substr(pos, nxt - pos);// tout le texte avant le mot
        if (nxt == string::npos) {
            break;
        }
        r += alt;              // le texte qui remplace le mot
        pos = nxt + mot.size();// avancer après le mot trouvé
    }
    return r;
}

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
