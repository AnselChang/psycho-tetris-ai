#include "models/TetrisBoard.h"
#include <iostream>

TetrisBoard::TetrisBoard() {

}

TetrisBoard::TetrisBoard(Grid<width, height> grid): grid(grid) {

}

Grid<10, 20>& TetrisBoard::getGrid() {
    return this->grid;
}