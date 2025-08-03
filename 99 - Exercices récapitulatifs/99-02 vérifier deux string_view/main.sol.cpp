#include <iostream>     // cout, endl via ostream
#include <string>       // string
#include <string_view>  // string_view
#include <cctype>       // toupper
#include <algorithm>    // transform, sort, unique

using namespace std;

string ensemble_trie(string_view s) {
   auto a = string(s);
   transform(a.cbegin(), a.cend(),a.begin(), ::toupper);
   sort(a.begin(),a.end());
   a.erase(unique(a.begin(), a.end()),a.end());
   return a;
}

bool verifier(string_view a, string_view b) {
   string ea = ensemble_trie(a);
   string eb = ensemble_trie(b);
   return a.size() == ea.size()
          and b.size() == eb.size()
          and ea == eb;
}

void tester(string_view a, string_view b) {
   cout << '\"' << a << "\" "
        << (verifier(a, b) ? "" : "in") << "compatible avec "
        << '\"' << b << '\"' << endl;
}

int main() {
   tester("abcdef","FEDBAC");
   tester("abcdef","xyz123");
   tester("abcA","cAba");
}
