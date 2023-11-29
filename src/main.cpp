#include <iostream>
#include "models/TetrisBoard.h"
#include "constants/Tetrominos.h"
#include "constants/TetrominoType.h"
#include "models/MoveableTetromino.h"

int main() {

    std::cout << "Hello, Wld!" << std::endl;

    TetrisBoard board(Grid<10, 20>({
        0b0000010000, // 0
        0b0100000000, // 1
        0b0000000000, // 2
        0b0000000000, // 3
        0b0000000000, // 4
        0b0000000000, // 5
        0b0000000000, // 6
        0b0010000000, // 7
        0b0000000000, // 8
        0b1111111111, // 9
        0b0111000000, // 10
        0b0000001000, // 11
        0b1111111111, // 12
        0b1111111111, // 13
        0b0001000000, // 14
        0b0000000100, // 15
        0b0000000000, // 16
        0b0100000000, // 17
        0b0000000100, // 18
        0b0010000000, // 19
    }));

    board.display();
    
    std::cout << board.clearLines() << std::endl;

    board.display();

    return 0;
}