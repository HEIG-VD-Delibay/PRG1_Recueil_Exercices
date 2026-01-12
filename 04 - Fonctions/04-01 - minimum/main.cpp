#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    int a = 5;
    int b = 2;
    int c = 9;
    cout << min(a, b, c);
    min(a, b, c) = 1;
    int &d = min(a, b, c);
    return 0;
}
