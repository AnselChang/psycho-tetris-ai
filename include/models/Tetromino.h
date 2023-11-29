/*
A tetromino consists of a tetris board for a piece for each rotation on the top-left corner
of the board.
*/

#ifndef TETROMINO_H
#define TETROMINO_H

#include "constants/TetrominoType.h"
#include "models/Grid.h"

class Tetromino {

private:
    TetrominoType type;

    // tetris board for each rotation. pieces have up to four possible rotations
    std::vector<Grid<4, 4>> rotations;

public:
    Tetromino(TetrominoType type, std::vector<Grid<4, 4>> rotations);

    Tetromino();

    TetrominoType getType() const;
    Grid<4,4> getRotation(int rotation) const;
    int getNumRotations() const;
};

#endif // TETROMINO_H