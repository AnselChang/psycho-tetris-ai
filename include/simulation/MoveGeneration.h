#ifndef MOVE_GENERATION_H
#define MOVE_GENERATION_H

#include "models/MoveableTetromino.h"
#include "simulation/ActionFrame.h"
#include "constants/TetrominoType.h"
#include <vector>

std::vector<MoveableTetromino> generateMoves(const TetrisBoard& board, const ActionFrames& frames, TetrominoType type);

#endif // MOVE_GENERATION_H