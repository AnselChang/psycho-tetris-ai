#include "models/TetrisBoard.h"
#include <iostream>

TetrisBoard::TetrisBoard() {

}

TetrisBoard::TetrisBoard(Grid<width, height> grid): grid(grid) {

}

void TetrisBoard::set(int x, int y, bool value) {
    grid.set(x, y, value);
}

bool TetrisBoard::get(int x, int y) const {
    return grid.get(x, y);
}

void TetrisBoard::display() const {
    grid.display();
}