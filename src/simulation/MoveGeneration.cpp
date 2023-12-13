#include "simulation/MoveGeneration.h"
#include "constants/Tetrominos.h"
#include "models/TetrisBoard.h"
#include <queue>


// generate the move for a specific rotation and specified number of translation inputs/left right
// also check for tuck/spins right before piece lock
// if piece locks before reaching the number of inputs, then return false 
bool generateMovesForRotationAndInputs(std::vector<MoveableTetromino>& moves, const TetrisBoard& board, const ActionFrames& frames, TetrominoType type, int rotation, int inputs) {

    // std::cout << "Generating moves for rotation " << rotation << " and inputs " << inputs << std::endl;

    // new piece at specified rotation and spawn position
    MoveableTetromino mt(type, rotation, TETROMINOS[type].getSpawnX(), TETROMINOS[type].getSpawnY());

    size_t numInputsSoFar = 0;
    size_t totalInputs = (inputs < 0 ? -inputs : inputs);
    int inputDirection = (inputs < 0 ? -1 : 1);
    size_t actionFrameIndex = 0;

    while (true) {

        // board.displayWithPiece(mt);
        
        ActionFrame frame = frames.get(actionFrameIndex);

        if (frame.action == Action::INPUT) {
            
            // if haven't reached target number of inputs, then perform input
            if (numInputsSoFar < totalInputs) {

                // std::cout << "shifting " << inputDirection << std::endl;

                const bool isLegalTranslation = mt.translateIfLegal(board, inputDirection, 0, 0);
                // if cannot shift, that means reached end of the board or blocks are in the way. terminate search in this entire input direction
                if (!isLegalTranslation) {
                    std::cout << "cannot shift, terminate search in this entire input direction" << std::endl;
                    return false;
                }

                // successful shift
                // std::cout << "successful shift" << std::endl;
                numInputsSoFar++;
            } else {
                // std::cout << "reached target number of inputs, skipping frame" << std::endl;
            }
        } else if (frame.action == Action::DROP) {

            // check if it's already a valid placement. if so, cannot drop but lock piece instead
            if (mt.isLegalPlacement(board)) {
                // std::cout << "PUSH_BACK VALID PLACEMENT" << std::endl;
                moves.push_back(mt);
                return true;
            } else {

                // std::cout << "dropping" << std::endl;

                // otherwise, drop
                const bool isLegal = mt.translateIfLegal(board, 0, 1, 0);

                // if current placement is not legal yet cannot drop, something went wrong
                if (!isLegal) throw std::runtime_error("generateMovesForRotationAndInputs: drop is not legal, something went wrong");
            }
        }
        actionFrameIndex++;
    }

}


std::vector<MoveableTetromino> generateMoves(const TetrisBoard& board, const ActionFrames& frames, TetrominoType type) {
    std::vector<MoveableTetromino> moves;

    const int spawnX = TETROMINOS[type].getSpawnX();
    const int spawnY = TETROMINOS[type].getSpawnY();

    for (int rotation = 0; rotation < TETROMINOS[type].getNumRotations(); rotation++) {

        MoveableTetromino spawn(type, rotation, spawnX, spawnY);
        spawn.getAsTetrisBoard().display();

        // no translation input case
        generateMovesForRotationAndInputs(moves, board, frames, type, rotation, 0);

        // loop once for 
        for (int inputDirection = -1; inputDirection <= 1; inputDirection += 2) {

            // std::cout << "inputDirection: " << inputDirection << std::endl;

            // check all left input cases where piece hasn't hit the left edge of the board
            size_t numTranslationInputs = 0;
            while (true) {

                numTranslationInputs++;

                const int directionalInputs = numTranslationInputs * inputDirection;

                // std::cout << "directionalInputs: " << directionalInputs << std::endl;

                // check if piece has hit the edge of the board. if so, break
                MoveableTetromino mt(type, rotation, TETROMINOS[type].getSpawnX() + directionalInputs, TETROMINOS[type].getSpawnY());
                mt.getAsTetrisBoard().display();
                if (!mt.isInBounds()) {
                    std::cout << "piece hit the edge of the board, break" << std::endl;
                    break;
                }

                // simulate the left inputs
                bool continueSearchInThisDirection = generateMovesForRotationAndInputs(moves, board, frames, type, rotation, directionalInputs);
                
                // if didn't even reach the number of inputs, and piece locked, then no point searching further
                if (!continueSearchInThisDirection) {
                    // std::cout << "piece locked before reaching the number of inputs, break" << std::endl;
                    break;
                }
            }
        }
    }

    
    return moves;
}