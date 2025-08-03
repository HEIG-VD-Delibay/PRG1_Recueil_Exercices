#include <iostream>
using namespace std;

int main() {
    string s = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Phasellus facilisis at dolor eget congue. Duis in lacus placerat ante consectetur tempor. Aliquam lorem nunc, laoreet quis feugiat accumsan, vulputate vitae justo.";
    cout << transformer(s, "abcdefgh.!,:", "fghabcde!,:.") << endl;
    cout << s << endl;
    cout << transformer(s, "fghabcde!,:.", "abcdefgh.!,:") << endl;
    cout << s << endl;
}
