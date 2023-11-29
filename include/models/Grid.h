/*
Stores an nxm grid of cells as a vector of bitboard rows
*/

#ifndef GRID_H
#define GRID_H

#include <bitset>
#include <array>
#include <initializer_list>
#include <vector>

template <int width, int height>
class Grid {
private:

    std::array<std::bitset<width>, height> rows;

public:

    // constructor that takes in a list of rows
    Grid();
    Grid(std::initializer_list<std::bitset<width>> rows);


    void set(int x, int y, bool value);
    bool get(int x, int y) const;
    void display() const;
};

#endif // TETRISBOARD_H