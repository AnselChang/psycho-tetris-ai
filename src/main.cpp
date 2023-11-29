#include <iostream>
#include "models/TetrisBoard.h"
#include "constants/Tetrominos.h"
#include "constants/TetrominoType.h"
#include "models/MoveableTetromino.h"
#include "simulation/ActionFrame.h"
#include "simulation/MoveGeneration.h"


#include <chrono>
using namespace std::chrono;

int main() {


    ActionFrames af(InputSequence("X."), 18);

    // fill board with all blocks for the bottom 12 rows
    TetrisBoard board;

    auto start = high_resolution_clock::now();
    std::vector<MoveableTetromino> moves = generateMoves(board, af, TetrominoType::I_TYPE);
    auto stop = high_resolution_clock::now();

    std::cout << "_______" << std::endl;
    for (MoveableTetromino mt : moves) {
        TetrisBoard copy = board;
        mt.blitToTetrisBoard(copy);
        copy.display();
    }

    auto duration = duration_cast<microseconds>(stop - start);
    std::cout << "Time taken by function: " << duration.count() << " microseconds" << std::endl;

    return 0;
}