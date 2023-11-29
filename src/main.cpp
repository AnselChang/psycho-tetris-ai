#include <iostream>
#include "models/TetrisBoard.h"
#include "constants/Tetrominos.h"
#include "constants/TetrominoType.h"
#include "models/MoveableTetromino.h"

int main() {

    std::cout << "Hello, Wld!" << std::endl;

    // iterate over all tetrominoMap
    for (auto const& tetromino : TETROMINOS) {
        std::cout << TETROMINO_NAMES[tetromino.first] << std::endl;
        tetromino.second.display();
    }


    return 0;
}