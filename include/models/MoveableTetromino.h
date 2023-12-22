#ifndef MOVEABLE_TETROMINO_H
#define MOVEABLE_TETROMINO_H

#include "constants/TetrominoType.h"
#include "models/Tetromino.h"

class TetrisBoard;

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

    // move tetromino if legal (no intersection with board and in bounds)
    // should only be a single action (only one paramter should be nonzero and have magnitude 1)
    // if move is illegal, do not move the piece and return false
    bool translateIfLegal(const TetrisBoard& tetrisBoard, int dx, int dy, int dr);

    TetrominoType getTetrominoType() const;
    Tetromino getTetromino() const;
    Grid<4,4> getGridAtCurrentRotation() const;

    // modifies the tetris board by blitting the tetromino to it
    void blitToTetrisBoard(TetrisBoard& tetrisBoard) const;
    TetrisBoard blitToNewTetrisBoard(const TetrisBoard& tetrisBoard) const;

    // returns a new TetrisBoard with the tetromino blitted to it
    TetrisBoard getAsTetrisBoard() const;

    // whether the tetromino in its current pose intersects a tetris board
    bool intersectsTetrisBoard(const TetrisBoard& tetrisBoard) const;

    // whether the tetromino in its current pose is in bounds a tetris board
    bool isInBounds(bool verbose = false) const;

    // whether the tetromino can lock to the given tetris board legally in its current pose
    bool isLegalPlacement(const TetrisBoard& tetrisBoard) const;

    void print() const;
};

#endif // MOVEABLE_TETROMINO_H