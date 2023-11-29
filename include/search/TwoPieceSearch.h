#ifndef TWO_PIECE_SEARCH_H
#define TWO_PIECE_SEARCH_H

#include "constants/TetrominoType.h"
#include "models/TetrisBoard.h"
#include "search/TwoPiecePlacement.h"
#include "simulation/ActionFrame.h"
#include "simulation/InputSequence.h"
#include "constants/GameSpeed.h"
#include <vector>

// Exhaustive search given a board and two pieces
class TwoPieceSearch {

private:

    TetrominoType firstPiece;
    TetrominoType secondPiece;
    TetrisBoard board;
    ActionFrames af;
    int level;

    std::vector<TwoPiecePlacement> placements;

public:

    TwoPieceSearch(TetrominoType firstPiece, TetrominoType secondPiece, TetrisBoard board, InputSequence sequence, int level);

    void search();

    void display();

};

#endif // TWO_PIECE_SEARCH_H