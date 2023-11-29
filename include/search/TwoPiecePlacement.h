#ifndef TWOPIECEPLACEMENT_H
#define TWOPIECEPLACEMENT_H

#include "models/MoveableTetromino.h"

// stores a single permutation of placements for the current and next pieces
struct TwoPiecePlacement {
    MoveableTetromino firstPiece;
    MoveableTetromino secondPiece;

    void display(TetrisBoard& board) const {
        TetrisBoard boardWithPlacement = firstPiece.blitToNewTetrisBoard(board);
        secondPiece.blitToTetrisBoard(boardWithPlacement);
        boardWithPlacement.display();
    }

};

#endif // TWOPIECEPLACEMENT_H