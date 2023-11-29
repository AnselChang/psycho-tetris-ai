#include <iostream>
#include "models/TetrisBoard.h"
#include "constants/Tetrominos.h"
#include "constants/TetrominoType.h"
#include "models/MoveableTetromino.h"
#include "simulation/ActionFrame.h"
#include "simulation/MoveGeneration.h"
#include "search/TwoPieceSearch.h"


#include <chrono>
using namespace std::chrono;

void testMoveGeneration(TetrisBoard& board) {

    ActionFrames af(InputSequence("X."), 18);

    auto start = high_resolution_clock::now();
    std::vector<MoveableTetromino> moves = generateMoves(board, af, TetrominoType::T_TYPE);
    auto stop = high_resolution_clock::now();

    std::cout << "_______" << std::endl;
    for (MoveableTetromino mt : moves) {
        board.displayWithPiece(&mt);
        // board.displayWithPiece();
    }
    auto duration = duration_cast<microseconds>(stop - start);
    std::cout << "Time taken by function: " << duration.count() << " microseconds" << std::endl;


}
void testSearch() {

    TetrisBoard board;
    TwoPieceSearch search(TetrominoType::J_TYPE, TetrominoType::T_TYPE, board, InputSequence("X..."), 18);

    auto start = high_resolution_clock::now();
    search.search();
    auto stop = high_resolution_clock::now();

    search.display();

    auto duration = duration_cast<milliseconds>(stop - start);
    std::cout << "Time taken by function: " << duration.count() << " milliseconds" << std::endl;

}

int main() {

    TetrisBoard board;
    // randomize bottom rows
    for (int y = 15; y < 20; y++) {
        for (int x = 0; x < 10; x++) {
            board.getGrid().set(x, y, rand() % 7);
        }
    }

    testMoveGeneration(board);

    return 0;
}