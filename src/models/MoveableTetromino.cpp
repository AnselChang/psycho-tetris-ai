#include "models/MoveableTetromino.h"
#include "constants/Tetrominos.h"

MoveableTetromino::MoveableTetromino(TetrominoType tetrominoType):
    tetrominoType(tetrominoType)
{}

MoveableTetromino::MoveableTetromino(TetrominoType tetrominoType, int r, int x, int y):
    tetrominoType(tetrominoType),
    rotation(r),
    x(x),
    y(y)
{}

TetrominoType MoveableTetromino::getTetrominoType() const {
    return this->tetrominoType;
}

Tetromino MoveableTetromino::getTetromino() const {
    return tetrominoMap[this->tetrominoType];
}

Grid<4,4> MoveableTetromino::getGridAtCurrentRotation() const {
    return tetrominoMap[this->tetrominoType].getRotation(this->rotation);
}

void MoveableTetromino::blitToTetrisBoard(TetrisBoard& tetrisBoard) const {
    Grid<4,4> grid = this->getGridAtCurrentRotation();
    
    // blit row by row using bitwise operations
    for (int y = 0; y < 4; y++) {

        // shift gridRow to the right by x
        const auto gridRow = grid.getRow(y);
        const std::bitset<10> shiftedGridRow(gridRow.to_ulong() << this->x);

        // get the row of the tetrisBoard that we are blitting to
        const int tetrisBoardRowIndex = this->y + y;
        const auto tetrisBoardRow = tetrisBoard.getGrid().getRow(tetrisBoardRowIndex);

        // blit the padded gridRow to the tetrisBoardRow
        tetrisBoard.getGrid().setRow(tetrisBoardRowIndex, shiftedGridRow | tetrisBoardRow);
    }

}

TetrisBoard MoveableTetromino::getAsTetrisBoard() const {
    TetrisBoard tetrisBoard;
    this->blitToTetrisBoard(tetrisBoard);
    return tetrisBoard;
}

bool MoveableTetromino::isInBounds() const {
    const Grid<4,4> grid = this->getGridAtCurrentRotation();
    const int maxXIndex = tetrominoMap[this->tetrominoType].getMaxXIndex(this->rotation);
    const int maxYIndex = tetrominoMap[this->tetrominoType].getMaxYIndex(this->rotation);

    const int relMinX = this->x;
    const int relMaxX = this->x + maxXIndex;
    const int relMinY = this->y;
    const int relMaxY = this->y + maxYIndex;

    // check if the tetromino is out of bounds of the 20 row x 10 col tetris board
    if (relMinX < 0 || relMaxX >= 10 || relMinY < 0 || relMaxY >= 20) {
        return false;
    }

    return true;
}