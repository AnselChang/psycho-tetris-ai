#include <iostream>
#include "models/TetrisBoard.h"
#include "constants/Tetrominos.h"
#include "constants/TetrominoType.h"
#include "models/MoveableTetromino.h"
#include "simulation/ActionFrame.h"

int main() {

    MoveableTetromino mt(TetrominoType::O_TYPE, 0, 3, -2);
    if (mt.isInBounds()) mt.getAsTetrisBoard().display();
    std::cout << "------" << std::endl;


    // for (int i = -2; i < 3; i++) {
    //     for (int j = -3; j < 2; j++) {
    //         MoveableTetromino mt(TetrominoType::T_TYPE, 0, i, j);
    //         std::cout << (mt.isInBounds() ? "bounds" : "out of bounds") << std::endl;
    //         if (mt.isInBounds()) mt.getAsTetrisBoard().display();
    //         std::cout << "------" << std::endl;
    //     }
    // }
    


    return 0;
}