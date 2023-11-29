#ifndef MOVEABLE_TETROMINO_H
#define MOVEABLE_TETROMINO_H

#include "constants/TetrominoType.h"
#include "models/Tetromino.h"
#include "models/TetrisBoard.h"

class MoveableTetromino {

private:
    const TetrominoType tetrominoType;
    const int numRotations;
    
    int rotation = 0;
    int x = 0;
    int y = 0;

    std::bitset<10> getShiftedRow(int row) const;
    
public:
    MoveableTetromino(TetrominoType tetrominoType);
    MoveableTetromino(TetrominoType tetrominoType, int r, int x, int y);

    // getters
    int getRotation() const;
    int getX() const;
    int getY() const;

    // setters
    void setPose(int r, int x, int y);

    TetrominoType getTetrominoType() const;
    Tetromino getTetromino() const;
    Grid<4,4> getGridAtCurrentRotation() const;

    // modifies the tetris board by blitting the tetromino to it
    void blitToTetrisBoard(TetrisBoard& tetrisBoard) const;

    // returns a new TetrisBoard with the tetromino blitted to it
    TetrisBoard getAsTetrisBoard() const;

    // whether the tetromino in its current pose intersects a tetris board
    bool intersectsTetrisBoard(const TetrisBoard& tetrisBoard) const;

    // whether the tetromino in its current pose is in bounds a tetris board
    bool isInBounds() const;

    // whether the tetromino can lock to the given tetris board legally in its current pose
    bool isLegalPlacement(const TetrisBoard& tetrisBoard) const;
};

#endif // MOVEABLE_TETROMINO_H