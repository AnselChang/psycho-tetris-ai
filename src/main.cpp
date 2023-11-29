#include <iostream>
#include "models/TetrisBoard.h"
#include "constants/Tetrominos.h"
#include "constants/TetrominoType.h"
#include "models/MoveableTetromino.h"
#include "simulation/ActionFrame.h"

int main() {

    ActionFrames frames(InputSequence("X.."), 19);
    frames.display();

    return 0;
}