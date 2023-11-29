#include "models/MoveableTetromino.h"
#include "constants/Tetrominos.h"

MoveableTetromino::MoveableTetromino(TetrominoType tetrominoType):
    tetrominoType(tetrominoType),
    numRotations(TETROMINOS[tetrominoType].getNumRotations())
{}

MoveableTetromino::MoveableTetromino(TetrominoType tetrominoType, int r, int x, int y):
    tetrominoType(tetrominoType),
    numRotations(TETROMINOS[tetrominoType].getNumRotations()),
    rotation(r),
    x(x),
    y(y)
{}

int MoveableTetromino::getRotation() const {
    return this->rotation;
}

int MoveableTetromino::getX() const {
    return this->x;
}

int MoveableTetromino::getY() const {
    return this->y;
}

void MoveableTetromino::setPose(int r, int x, int y) {
    this->rotation = r % this->numRotations;
    this->x = x;
    this->y = y;
}

TetrominoType MoveableTetromino::getTetrominoType() const {
    return this->tetrominoType;
}

Tetromino MoveableTetromino::getTetromino() const {
    return TETROMINOS[this->tetrominoType];
}

Grid<4,4> MoveableTetromino::getGridAtCurrentRotation() const {
    return TETROMINOS[this->tetrominoType].getRotation(this->rotation);
}

std::bitset<10> MoveableTetromino::getShiftedRow(int row) const {

    Grid<4,4> grid = this->getGridAtCurrentRotation();

    // shift gridRow to the right by x
    const auto gridRow = grid.getRow(row);
    const std::bitset<10> paddedGridRow(gridRow.to_ulong());
    const std::bitset<10> shiftedGridRow = (this->x > 0) ? (paddedGridRow << this->x) : (paddedGridRow >> -this->x);

    return shiftedGridRow;
}

void MoveableTetromino::blitToTetrisBoard(TetrisBoard& tetrisBoard) const {

    if (!this->isInBounds()) {
        throw std::runtime_error("Tetromino is out of bounds");
    }
    
    // blit row by row using bitwise operations
    for (int y = 0; y < 4; y++) {

        const std::bitset<10> shiftedGridRow = this->getShiftedRow(y);

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

// based on the min and max x and y indices of the tetromino, check if it is in bounds
bool MoveableTetromino::isInBounds() const {
    const Grid<4,4> grid = this->getGridAtCurrentRotation();
    const int minXIndex = TETROMINOS[this->tetrominoType].getMinXIndex(this->rotation);
    const int minYIndex = TETROMINOS[this->tetrominoType].getMinYIndex(this->rotation);
    const int maxXIndex = TETROMINOS[this->tetrominoType].getMaxXIndex(this->rotation);
    const int maxYIndex = TETROMINOS[this->tetrominoType].getMaxYIndex(this->rotation);

    const int relMinX = this->x + minXIndex;
    const int relMaxX = this->x + maxXIndex;
    const int relMinY = this->y + minYIndex;
    const int relMaxY = this->y + maxYIndex;

    std::cout << "relMinX: " << relMinX << std::endl;
    std::cout << "relMaxX: " << relMaxX << std::endl;
    std::cout << "relMinY: " << relMinY << std::endl;
    std::cout << "relMaxY: " << relMaxY << std::endl;

    // check if the tetromino is out of bounds of the 20 row x 10 col tetris board
    if (relMinX < 0 || relMaxX >= 10 || relMinY < 0 || relMaxY >= 20) {
        return false;
    }

    return true;
}

// precondition: the tetromino is in bounds
bool MoveableTetromino::intersectsTetrisBoard(const TetrisBoard& tetrisBoard) const {
    
    // check if it insersects row by row
    for (int y = 0; y < 4; y++) {

        const std::bitset<10> shiftedGridRow = this->getShiftedRow(y);

        // get the row of the tetrisBoard that we are comparing with
        const int tetrisBoardRowIndex = this->y + y;
        const auto tetrisBoardRow = tetrisBoard.getRow(tetrisBoardRowIndex);

        // check if the shiftedGridRow intersects with the tetrisBoardRow
        if ((shiftedGridRow & tetrisBoardRow).any()) {
            return true;
        }
    }
    // if we get here, then the tetromino does not intersect the tetris board
    return false;
}

bool MoveableTetromino::isLegalPlacement(const TetrisBoard& tetrisBoard) const {

    // if the tetromino is out of bounds, then it is not a legal placement
    if (!this->isInBounds()) return false;

    // if the tetromino intersects the tetris board, then it is not a legal placement
    if (this->intersectsTetrisBoard(tetrisBoard)) return false;

    // Create tetromino shifted by one row down for intersection detection
    MoveableTetromino shiftedTetromino(tetrominoType, rotation, x, y + 1);

    // it is legal only if shiftedTetromino either intersects the tetris board or is out of bounds
    return !shiftedTetromino.isInBounds() || shiftedTetromino.intersectsTetrisBoard(tetrisBoard);

}