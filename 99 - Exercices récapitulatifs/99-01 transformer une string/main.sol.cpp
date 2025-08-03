#include <algorithm>  // transform
#include <cassert>    // assert
#include <cctype>     // isupper, toupper
#include <iostream>   // cout, endl via ostream
#include <string>     // string
#include <string_view>// string_view

using namespace std;

size_t transformer(string &s,     // par référence car modifié
                   string from,   // par valeur car besoin d'une copie
                   string_view to)// via string_view car en lecture seulement
{
    assert(from.size() == to.size());
    size_t nb_of_changes = 0;
    transform(from.cbegin(), from.cend(),
              from.begin(), ::toupper);
    for (char &c: s) {
        size_t p = from.find(::toupper(c));
        if (p != string::npos) {
            ++nb_of_changes;
            c = isupper(c) ? ::toupper(to[p]) : ::tolower(to[p]);
        }
    }
    return nb_of_changes;
}

int main() {
    string s = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Phasellus facilisis at dolor eget congue. Duis in lacus placerat ante consectetur tempor. Aliquam lorem nunc, laoreet quis feugiat accumsan, vulputate vitae justo.";
    cout << transformer(s, "abcdefgh.!,:", "hgfedcab!.:,") << endl;
    cout << s << endl;
    cout << transformer(s, "hgfedcab!.:,", "abcdefgh.!,:") << endl;
    cout << s << endl;
}
