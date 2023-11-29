#include <iostream>
#include "models/TetrisBoard.h"
#include "constants/Tetrominos.h"
#include "constants/TetrominoType.h"
#include "models/MoveableTetromino.h"

int main() {

    std::cout << "Hello, Wld!" << std::endl;

    MoveableTetromino moveableTetromino(TetrominoType::I_TYPE, 1, 0, 0);
    moveableTetromino.getAsTetrisBoard().getGrid().display();
    return 0;
}