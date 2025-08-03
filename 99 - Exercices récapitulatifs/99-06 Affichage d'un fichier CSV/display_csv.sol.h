#ifndef DISPLAY_CSV_H
#define DISPLAY_CSV_H

#include <string_view>

class File_not_found {};

void display_csv(std::string_view filename, char separator, int col_size);

#endif
