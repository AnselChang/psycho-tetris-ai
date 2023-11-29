#include "simulation/MoveGeneration.h"
#include "constants/Tetrominos.h"
#include <queue>

struct Position {
    int actionFrameIndex; // not actual frame index
    int x;
    int y;
};


void generateMovesForRotation(std::vector<MoveableTetromino>& moves, const TetrisBoard& board, const ActionFrames& frames, TetrominoType type, int rotation) {

    bool visited[20][10]; // [y][x]
    for (int y = 0; y < 20; y++) {
        for (int x = 0; x < 10; x++) {
            visited[y][x] = false;
        }
    }

    std::queue<Position> queue;
    
    int startX = TETROMINOS[type].getSpawnX();
    queue.push({0, startX, 0});

    while (!queue.empty()) {
        Position position = queue.front();
        queue.pop();

        ActionFrame frame = frames.get(position.actionFrameIndex);

        if (frame.action == Action::INPUT) {
            
            // loop through possible translation input
            for (int newX = position.x - 1; newX <= position.x + 1; newX++) {
                MoveableTetromino mt(type, rotation, newX, position.y);

                // ignore if out of bounds
                if (!mt.isInBounds()) continue;

                // ignore if colliding with board (after the horizontal shift)
                if (mt.intersectsTetrisBoard(board)) continue;

                // ignore if visited
                if (visited[mt.getY()][mt.getX()]) continue;

                // Register the input by adding to visited and pushing to queue
                visited[mt.getY()][mt.getX()] = true;
                queue.push({position.actionFrameIndex + 1, mt.getX(), mt.getY()});
            }
        } else { // frame.action == Action::DROP

            MoveableTetromino mt(type, rotation, position.x, position.y);

            // check if it's already a valid placement. if so, cannot drop but lock piece instead
            if (mt.isLegalPlacement(board)) {
                moves.push_back(mt);
                continue;
            } else {                
                // asert drop is legal. REMOVE IN PRODUCTION
                MoveableTetromino dropMt(type, rotation, position.x, position.y + 1);
                if (!dropMt.isInBounds() || dropMt.intersectsTetrisBoard(board)) throw std::runtime_error("generateMovesForRotation: drop is not legal, something went wrong");
                
                // otherwise, drop and add to queue
                queue.push({position.actionFrameIndex + 1, mt.getX(), mt.getY() + 1});
            }

        }
        
    }


}

std::vector<MoveableTetromino> generateMoves(const TetrisBoard& board, const ActionFrames& frames, TetrominoType type) {
    std::vector<MoveableTetromino> moves;

    for (int rotation = 0; rotation < TETROMINOS[type].getNumRotations(); rotation++) {
        generateMovesForRotation(moves, board, frames, type, rotation);
    }

    
    return moves;
}