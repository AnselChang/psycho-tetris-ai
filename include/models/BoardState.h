#ifndef __BOARDSTATE_H__
#define __BOARDSTATE_H__

#include "models/TetrisBoard.h"
#include "constants/TetrominoType.h"
#include <string>

/*
Complete board state with board, current piece, next piece, level, lines
*/
struct BoardState {
    TetrisBoard board;
    TetrominoType currentPiece;
    TetrominoType nextPiece;
    int level;
    int lines;
    std::string inputFrameTimeline;

    void display() const {
        std::cout << "BoardState with:" << std::endl;
        std::cout << "currentPiece: " << currentPiece << std::endl;
        std::cout << "nextPiece: " << nextPiece << std::endl;
        std::cout << "level: " << level << std::endl;
        std::cout << "lines: " << lines << std::endl;
        std::cout << "inputFrameTimeline: " << inputFrameTimeline << std::endl;
        board.display();
    }
};

#endif // __BOARDSTATE_H__