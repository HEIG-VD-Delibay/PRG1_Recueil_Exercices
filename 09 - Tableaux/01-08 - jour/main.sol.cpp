#include <array>
#include <iostream>
#include <string>

using namespace std;

enum class Day { ERROR,
                 LUNDI,
                 MARDI,
                 MERCREDI,
                 JEUDI,
                 VENDREDI,
                 SAMEDI,
                 DIMANCHE };
const std::array<string, 8> DAY{"ERROR", "LUNDI", "MARDI", "MERCREDI", "JEUDI", "VENDREDI", "SAMEDI", "DIMANCHE"};

string day_to_string(Day d) {
    if (d >= Day::LUNDI and d <= Day::DIMANCHE)
        return DAY[size_t(d)];

    return DAY[size_t(Day::ERROR)];
}

Day string_to_day(const string &s) {
    for (size_t i = 1; i < DAY.size(); ++i)
        if (DAY[i] == s)
            return Day(i);
    return Day::ERROR;
}

int main(int argc, char *argv[]) {

    for (size_t i = 0; i < 8; ++i)
        cout << "day_to_string(Day(" << i << ")) => \"" << day_to_string(Day(i)) << "\"" << endl;

    for (size_t i = 9; i <= 11; ++i)
        cout << "day_to_string(Day(" << i << ")) => \"" << day_to_string(Day(i)) << "\"" << endl;

    cout << "---" << endl;

    for (size_t i = 0; i < 8; ++i)
        cout << "string_to_day(\"" << DAY[i] << "\") => Day(" << (int) string_to_day(DAY[i]) << ")" << endl;

    cout << "string_to_day(\"not a day\") => Day(" << (int) string_to_day("not a day") << ")" << endl;
    return 0;
}
