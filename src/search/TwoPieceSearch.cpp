#include "search/TwoPieceSearch.h"
#include "simulation/MoveGeneration.h"

TwoPieceSearch::TwoPieceSearch(TetrominoType firstPiece, TetrominoType secondPiece, TetrisBoard board, InputSequence sequence, int level):
    firstPiece(firstPiece),
    secondPiece(secondPiece),
    board(board),
    af(ActionFrames(sequence, level)),
    level(level) 
{}

void TwoPieceSearch::search() {

    std::vector<MoveableTetromino> firstPieceMoves = generateMoves(board, ActionFrames(InputSequence("X."), 18), firstPiece);

    for (MoveableTetromino firstPieceMove : firstPieceMoves) {

        TetrisBoard boardWithFirstPiece = firstPieceMove.blitToNewTetrisBoard(board);
        std::vector<MoveableTetromino> secondPieceMoves = generateMoves(boardWithFirstPiece, ActionFrames(InputSequence("X."), 18), secondPiece);

        for (MoveableTetromino secondPieceMove : secondPieceMoves) {
            placements.push_back(TwoPiecePlacement{firstPieceMove, secondPieceMove});
        }
    }
}

void TwoPieceSearch::display() {
    for (TwoPiecePlacement placement : placements) {
        board.displayWithPiece(&placement.firstPiece, &placement.secondPiece);
    }
}