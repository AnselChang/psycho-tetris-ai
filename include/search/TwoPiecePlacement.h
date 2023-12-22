#ifndef TWOPIECEPLACEMENT_H
#define TWOPIECEPLACEMENT_H

#include "models/MoveableTetromino.h"
#include "models/TetrisBoard.h"

// stores a single permutation of placements for the current and next pieces
class TwoPiecePlacement {

public:
    const MoveableTetromino firstPiece;
    const MoveableTetromino secondPiece;
    const TetrisBoard resultingBoard;

    TwoPiecePlacement(TetrisBoard resultingBoard, MoveableTetromino firstPiece, MoveableTetromino secondPiece):
        firstPiece(firstPiece),
        secondPiece(secondPiece),
        resultingBoard(resultingBoard)
    {}

};

#endif // TWOPIECEPLACEMENT_H