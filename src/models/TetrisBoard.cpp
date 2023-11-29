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

// run any line clears and return the number of lines cleared
// detect full lines by checking if all bits are set
int TetrisBoard::clearLines() {
    int linesCleared = 0;
    
    // iterate through each row starting from the bottom
    for (int y = height - 1; y >= 0; y--) {
        auto row = this->getRow(y);
        if (row.all()) {
            linesCleared++;
        } else {
            // shift all rows above the current row down by the number of lines cleared
            if (linesCleared > 0) {
                this->grid.setRow(y + linesCleared, row);
            }
        }
    }

    // clear the top lines
    for (int y = 0; y < linesCleared; y++) {
        this->grid.setRow(y, std::bitset<width>());
    }

    return linesCleared;

}