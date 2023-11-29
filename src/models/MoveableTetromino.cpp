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