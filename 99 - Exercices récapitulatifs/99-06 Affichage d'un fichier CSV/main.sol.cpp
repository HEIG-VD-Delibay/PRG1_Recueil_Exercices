#include "display_csv.sol.h"
#include <cstdlib>
#include <iostream>


using namespace std;

int main() {
    printf("Content of data.csv\n");
    try {
        display_csv("data.csv", ',', 10);
    } catch (File_not_found &e) {
        cerr << "File not found \n";
        exit(-1);
    }
}
