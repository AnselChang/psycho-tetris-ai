#include "models/TetrisBoard.h"
#include <iostream>

TetrisBoard::TetrisBoard() {

}

TetrisBoard::TetrisBoard(Grid<width, height> grid): grid(grid) {

}

Grid<10, 20>& TetrisBoard::getGrid() {
    return this->grid;
}

std::bitset<10> TetrisBoard::getRow(int y) const {
    return this->grid.getRow(y);
}

bool TetrisBoard::get(int x, int y) const {
    return this->grid.get(x, y);
}

void TetrisBoard::display() const {
    this->grid.display();
}