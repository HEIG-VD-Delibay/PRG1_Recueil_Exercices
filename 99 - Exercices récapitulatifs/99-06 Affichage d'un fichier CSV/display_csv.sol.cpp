#include "display_csv.sol.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>

using namespace std;

void display_csv(string_view filename, char separator, int col_size) {
    ifstream file(string(filename).c_str());
    if (not file)
        throw File_not_found{};

    string line;
    while (getline(file, line)) {
        stringstream s(line);
        string element;
        while (getline(s, element, separator))
            cout << setw(col_size) << element;
        cout << endl;
    }
}
