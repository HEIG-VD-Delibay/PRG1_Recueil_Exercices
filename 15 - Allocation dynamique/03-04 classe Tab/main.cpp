#include <iostream>

using namespace std;

int main() {

    const size_t n = 3;

    try {
        cout << "------------" << endl;
        cout << "   tab1     " << endl;
        cout << "------------" << endl;
        Tab<int> tab1(n);
        for (size_t i = 0; i < n; ++i) {
            tab1.at(i) = (int) i;
        }
        cout << tab1 << endl;
        cout << "size : " << tab1.size() << endl;
        cout << endl;

        cout << "------------" << endl;
        cout << "   tab2     " << endl;
        cout << "------------" << endl;
        Tab<int> tab2(n);
        tab2 = tab1;
        cout << tab2 << endl;
        cout << "size : " << tab2.size() << endl;
        cout << endl;

        cout << "------------" << endl;
        cout << "   tab3     " << endl;
        cout << "------------" << endl;
        const Tab<int> tab3(tab1);
        cout << tab3 << endl;
        cout << "size : " << tab3.size() << endl;
        cout << endl;

        cout << "------------" << endl;
        cout << "   [] / at  " << endl;
        cout << "------------" << endl;
        cout << "tab1[0]     = 1; " << endl;
        tab1[0] = 1;
        cout << "tab1[0]     : " << tab1[0] << endl;
        cout << endl;
        cout << "tab1.at(1)  = 2; " << endl;
        tab1.at(2) = 2;
        cout << "tab1.at(1)  : " << tab1.at(2) << endl;

        try {
            cout << "tab1[3]     : " << tab1[3] << endl;
            cout << "tab3.at(3)  : " << tab3.at(3) << endl;
        } catch (out_of_range &e) {
            cout << "exception : " << e.what() << endl;
        }

        cout << endl;

    } catch (bad_alloc &e) {
        cout << e.what() << endl;
    }

    cout << endl;
    cout << "fin de programme" << endl;
    return EXIT_SUCCESS;
}
