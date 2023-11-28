#include "models/TetrisBoard.h"
#include <iostream>

void TetrisBoard::set(int x, int y, bool value) {
    if (x >= 0 && x < width && y >= 0 && y < height) {
        rows[y].set(x, value);
    }
}

bool TetrisBoard::get(int x, int y) const {
    if (x >= 0 && x < width && y >= 0 && y < height) {
        return rows[y].test(x);
    }
    return false; // Return false if coordinates are out of bounds
}

void TetrisBoard::display() const {
    for (const auto& row : rows) {
        for (int i = 0; i < width; ++i) {
            std::cout << (row.test(i) ? 'X' : '-') << ' ';
        }
        std::cout << '\n';
    }
}