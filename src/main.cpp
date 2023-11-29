#include <iostream>
#include "models/TetrisBoard.h"
#include "constants/Tetrominos.h"
#include "constants/TetrominoType.h"
#include "models/MoveableTetromino.h"

int main() {

    std::cout << "Hello, Wld!" << std::endl;

    for (int i = -2; i < 9; i++) {
        MoveableTetromino moveableTetromino(TetrominoType::I_TYPE, 0, i, 0);
        moveableTetromino.getAsTetrisBoard().getGrid().display();
        std::cout << (moveableTetromino.isInBounds() ? "true" : "false") << std::endl;
    }

    return 0;
}