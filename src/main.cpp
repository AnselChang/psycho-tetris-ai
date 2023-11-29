#include <iostream>
#include "models/TetrisBoard.h"
#include "constants/Tetrominos.h"
#include "constants/TetrominoType.h"
#include "models/MoveableTetromino.h"
#include "simulation/ActionFrame.h"

int main() {

    for (int i = 0; i < 7; i++) {
        TetrominoType type = TetrominoType(i);
        std::cout << TETROMINO_NAMES[type] << std::endl;
        TETROMINOS[type].display();
    }

    return 0;
}