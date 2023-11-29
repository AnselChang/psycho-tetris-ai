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
    std::vector<int> maxXIndex; // the maximum x index for each rotation
    std::vector<int> maxYIndex; // the maximum y index for each rotation

public:
    Tetromino(TetrominoType type, std::vector<Grid<4, 4>> rotations);

    Tetromino();

    TetrominoType getType() const;
    Grid<4,4> getRotation(int rotation) const;
    int getNumRotations() const;

    // returns the maximum x and y index for the given rotation
    int getMaxXIndex(int rotation) const;
    int getMaxYIndex(int rotation) const;


    void display() const;
};

#endif // TETROMINO_H