#include "models/TetrisBoard.h"
#include "models/MoveableTetromino.h"
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

void TetrisBoard::displayWithPiece(MoveableTetromino* mt, MoveableTetromino* mt2) const {
    Grid<10, 20> grid = this->grid;

    Grid<10, 20>* p1 = mt ? &(mt->getAsTetrisBoard().getGrid()) : nullptr;
    Grid<10, 20>* p2 = mt2 ? &(mt2->getAsTetrisBoard().getGrid()) : nullptr;

    for (int y = 0; y < 20; y++) {
        for (int x = 0; x < 10; x++) {

            char c = '.';
            if (grid.get(x, y)) {
                c = 'X';
            } else if (p1 && p1->get(x,y)) {
                c = '1';
            } else if (p2 && p2->get(x,y)) {
                c = '2';
            }
            std::cout << c << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
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