/*
Stores an nxm grid of cells as a vector of bitboard rows
*/

#ifndef GRID_H
#define GRID_H

#include <bitset>
#include <array>
#include <initializer_list>
#include <vector>
#include <iostream>

template <int width, int height>
class Grid {
private:

    std::array<std::bitset<width>, height> rows;

public:

    Grid() {}

    Grid(std::initializer_list<std::bitset<width>> rows) {
        std::copy(rows.begin(), rows.end(), this->rows.begin());
    }

    void set(int x, int y, bool value) {
        rows[y].set(x, value);
    }

    bool get(int x, int y) const {
        return rows[y].test(x);
    }

    void setRow(int y, std::bitset<width> row) {
        rows[y] = row;
    }

    std::bitset<width> getRow(int y) const {
        return rows[y];
    }

    void display() const {
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; ++x) {
                std::cout << (get(x, y) ? "X" : ".") << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
};

#endif // TETRISBOARD_H