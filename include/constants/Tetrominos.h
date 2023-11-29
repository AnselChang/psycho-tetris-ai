#ifndef TETROMINOS_H
#define TETROMINOS_H

#include <map>
#include <string>
#include "models/Tetromino.h"
#include "constants/TetrominoType.h"

extern std::map<TetrominoType, Tetromino> TETROMINOS;
extern std::map<TetrominoType, std::string> TETROMINO_NAMES;


#endif // TETROMINOS_H