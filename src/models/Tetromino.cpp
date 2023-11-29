#include "models/Tetromino.h"
#include "models/Grid.h"

Tetromino::Tetromino(TetrominoType type, std::vector<Grid<4,4>> rotations) {
    this->type = type;
    this->rotations = rotations;
}

TetrominoType Tetromino::getType() const {
    return this->type;
}

Grid<4,4> Tetromino::getRotation(int rotation) const {
    return this->rotations[rotation];
}

int Tetromino::getNumRotations() const {
    return this->rotations.size();
}