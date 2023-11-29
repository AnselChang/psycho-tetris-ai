#include "models/Grid.h"
#include <iostream>

template <int width, int height>
Grid<width, height>::Grid() {
    for (int i = 0; i < height; i++) {
        rows.push_back(std::bitset<width>(0));
    }
}

template <int width, int height>
Grid<width, height>::Grid(std::initializer_list<std::bitset<width>> rows) {
    for (auto& row : rows) {
        this->rows.push_back(row);
    }
}

template <int width, int height>
void Grid<width, height>::set(int x, int y, bool value) {
    rows[y].set(x, value);
}

template <int width, int height>
bool Grid<width, height>::get(int x, int y) const {
    return rows[y].test(x);
}

template <int width, int height>
void Grid<width, height>::display() const {
    for (auto& row : rows) {
        std::cout << row << std::endl;
    }
}