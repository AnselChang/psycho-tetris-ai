#include "models/MoveableTetromino.h"
#include "simulation/ActionFrame.h"
#include "constants/TetrominoType.h"
#include <vector>

std::vector<MoveableTetromino> generateMoves(const TetrisBoard& board, const ActionFrames& frames, TetrominoType type);