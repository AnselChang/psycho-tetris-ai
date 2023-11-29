#include <iostream>
#include "models/TetrisBoard.h"
#include "constants/Tetrominos.h"
#include "constants/TetrominoType.h"
#include "models/MoveableTetromino.h"

int main() {

    std::cout << "Hello, Wld!" << std::endl;

    MoveableTetromino moveableTetromino(TetrominoType::I_TYPE, 0, 0, 19);

    std::cout << (moveableTetromino.isInBounds() ? "inbounds" : "not in bounds") << std::endl;
    std::cout << (moveableTetromino.isLegalPlacement(TetrisBoard()) ? "legal" : "not lega") << std::endl;

    TetrisBoard board = moveableTetromino.getAsTetrisBoard();
    board.display();

    


    return 0;
}