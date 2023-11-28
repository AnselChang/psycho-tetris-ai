#include "models/TetrisBoard.h"
#include <iostream>

TetrisBoard::TetrisBoard() {
    // Initialize all rows to empty
    for (auto& row : rows) {
        row.reset();
    }
}

TetrisBoard::TetrisBoard(std::initializer_list<std::bitset<width>> rows) {
    // Initialize all rows to empty
    for (auto& row : this->rows) {
        row.reset();
    }

    // Copy the rows from the initializer list
    int i = 0;
    for (auto& row : rows) {
        this->rows[i++] = row;
    }
}

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