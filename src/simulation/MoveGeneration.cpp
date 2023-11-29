#include "simulation/MoveGeneration.h"
#include "constants/Tetrominos.h"
#include <queue>

struct Position {
    int actionFrameIndex; // not actual frame index
    int frameIndex; // actual frame index
    int x;
    int y;
};

class Compare
{
public:
    bool operator()(const Position& lhs, const Position& rhs) {
        return lhs.frameIndex > rhs.frameIndex;
    }
};


void generateMovesForRotation(std::vector<MoveableTetromino>& moves, const TetrisBoard& board, const ActionFrames& frames, TetrominoType type, int rotation) {

    // pad to avoid negative indices
    const int VISITED_OFFSET = 2;

    bool visited[20+VISITED_OFFSET][10+VISITED_OFFSET]; // [y][x]
    for (int y = 0; y < 20+VISITED_OFFSET; y++) {
        for (int x = 0; x < 10+VISITED_OFFSET; x++) {
            visited[y][x] = false;
        }
    }

    std::priority_queue<Position, std::vector<Position>, Compare> queue; // lowest FRAME INDEX (not actionindex) first
    
    int startX = TETROMINOS[type].getSpawnX();
    int startY = TETROMINOS[type].getSpawnY();
    visited[startY+VISITED_OFFSET][startX+VISITED_OFFSET] = true;
    queue.push({0, 0, startX, startY});

    while (!queue.empty()) {
        Position position = queue.top();
        queue.pop();

        ActionFrame frame = frames.get(position.actionFrameIndex);

        MoveableTetromino originalMt(type, rotation, position.x, position.y);
        // std::cout << "original" << std::endl;
        // originalMt.blitToNewTetrisBoard(board).display();

        if (frame.action == Action::INPUT) {

            // std::cout << "input" << std::endl;
            
            // loop through possible translation input
            for (int newX = position.x - 1; newX <= position.x + 1; newX++) {
                // std::cout << (position.x-newX) << std::endl;
                MoveableTetromino mt(type, rotation, newX, position.y);

                // std::cout << "before bounds" << std::endl;
                // ignore if out of bounds
                if (!mt.isInBounds()) continue;


                // std::cout << "before collide" << std::endl;
                // ignore if colliding with board (after the horizontal shift)
                if (mt.intersectsTetrisBoard(board)) continue;

                // std::cout << "before visited" << std::endl;
                // ignore if visited
                if (newX != position.x && visited[mt.getY()+VISITED_OFFSET][mt.getX()+VISITED_OFFSET]) continue;

                // mt.blitToNewTetrisBoard(board).display();

                // std::cout << "before register" << std::endl;
                // Register the input by adding to visited and pushing to queue
                visited[mt.getY()+VISITED_OFFSET][mt.getX()+VISITED_OFFSET] = true;
                int frameIndex = frames.get(position.actionFrameIndex+1).frameIndex;
                queue.push({position.actionFrameIndex + 1, frameIndex, mt.getX(), mt.getY()});
                // std::cout << "after register" << std::endl;
            }
        } else { // frame.action == Action::DROP

            // std::cout << "drop" << std::endl;

            MoveableTetromino mt(type, rotation, position.x, position.y);

            // check if it's already a valid placement. if so, cannot drop but lock piece instead
            if (mt.isLegalPlacement(board)) {

                // std::cout << "LOCK" << std::endl;
                // mt.blitToNewTetrisBoard(board).display();

                moves.push_back(mt);
                continue;
            } else {                
                // asert drop is legal. REMOVE IN PRODUCTION
                MoveableTetromino dropMt(type, rotation, position.x, position.y + 1);
                // std::cout << "after drop" << std::endl;
                if (!dropMt.isInBounds() || dropMt.intersectsTetrisBoard(board)) throw std::runtime_error("generateMovesForRotation: drop is not legal, something went wrong");
                // dropMt.blitToNewTetrisBoard(board).display();

                // otherwise, drop and add to queue
                visited[mt.getY()+VISITED_OFFSET + 1][mt.getX()+VISITED_OFFSET] = true;
                int frameIndex = frames.get(position.actionFrameIndex+1).frameIndex;
                queue.push({position.actionFrameIndex + 1, frameIndex, mt.getX(), mt.getY() + 1});
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