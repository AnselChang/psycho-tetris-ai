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
        boardWithFirstPiece.clearLines();
        std::vector<MoveableTetromino> secondPieceMoves = generateMoves(boardWithFirstPiece, ActionFrames(InputSequence("X."), 18), secondPiece);

        for (MoveableTetromino secondPieceMove : secondPieceMoves) {
            TetrisBoard resultingBoard = secondPieceMove.blitToNewTetrisBoard(boardWithFirstPiece);
            resultingBoard.clearLines();
            placements.push_back(TwoPiecePlacement{resultingBoard, firstPieceMove, secondPieceMove});
        }
    }
}

void TwoPieceSearch::display() {
    for (TwoPiecePlacement placement : placements) {
        placement.resultingBoard.display();
    }
}

int TwoPieceSearch::getNumPlacements() const {
    return placements.size();
}