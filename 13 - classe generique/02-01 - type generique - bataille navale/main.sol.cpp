#include <array>
#include <iostream>
#include <string>

using namespace std;

//------------------------------------------------------------
enum class Cell { Eau,
                  Bateau,
                  Touche,
                  Coule };
const array CellChar = {'.', 'B', 'x', 'O'};

//------------------------------------------------------------
template<typename T, size_t width>
using Row = array<T, width>;

//------------------------------------------------------------
template<typename T, size_t width, size_t height>
using Grid = array<Row<T, width>, height>;

//------------------------------------------------------------
template<typename T, size_t width, size_t height>
ostream &operator<<(ostream &os, const Grid<T, width, height> &g);

//------------------------------------------------------------
int main() {
    const Cell E = Cell::Eau;
    const Cell B = Cell::Bateau;
    const Cell T = Cell::Touche;
    const Cell C = Cell::Coule;

    using Game = Grid<Cell, 8, 6>;

    Game game = {{{E, E, E, E, T, T, B, E},
                  {E, E, E, E, E, E, E, E},
                  {E, E, B, E, E, C, E, E},
                  {E, E, T, E, E, C, E, E},
                  {E, E, B, E, E, C, E, E},
                  {E, E, E, E, E, E, E, E}}};

    cout << game << endl;
}

//------------------------------------------------------------
template<typename T, size_t width, size_t heigth>
ostream &operator<<(ostream &os, const Grid<T, width, heigth> &g) {
    os << std::string(width + 2, '-') << endl;
    for (const Row<T, width> &r: g) {
        os << '|';
        for (Cell c: r)
            os << CellChar.at((size_t) c);
        os << '|' << endl;
    }
    return os << string(width + 2, '-') << endl;
}
