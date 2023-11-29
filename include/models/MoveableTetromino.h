#ifndef MOVEABLE_TETROMINO_H
#define MOVEABLE_TETROMINO_H

#include "constants/TetrominoType.h"
#include "models/Tetromino.h"
#include "models/TetrisBoard.h"

class MoveableTetromino {

private:
    const TetrominoType tetrominoType;
    
    int rotation = 0;
    int x = 0;
    int y = 0;
    
public:
    MoveableTetromino(TetrominoType tetrominoType);
    MoveableTetromino(TetrominoType tetrominoType, int r, int x, int y);

    TetrominoType getTetrominoType() const;
    Tetromino getTetromino() const;
    Grid<4,4> getGridAtCurrentRotation() const;

    // modifies the tetris board by blitting the tetromino to it
    void blitToTetrisBoard(TetrisBoard& tetrisBoard) const;

    // returns a new TetrisBoard with the tetromino blitted to it
    TetrisBoard getAsTetrisBoard() const;
};

#endif // MOVEABLE_TETROMINO_H