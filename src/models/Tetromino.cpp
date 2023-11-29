#include "models/Tetromino.h"
#include "models/Grid.h"

Tetromino::Tetromino():
    type(UNDEFINED_TYPE)
{}

Tetromino::Tetromino(TetrominoType type, std::vector<Grid<4,4>> rotations) {
    this->type = type;
    this->rotations = rotations;

    // calculate the max x and y indices for each rotation
    for (int i = 0; i < rotations.size(); i++) {
        int maxX = 0;
        int maxY = 0;
        for (int y = 0; y < 4; y++) {
            auto row = rotations[i].getRow(y).to_ulong();
            for (int x = 0; x < 4; x++) {
                if (row & (1 << x)) {
                    if (x > maxX) {
                        maxX = x;
                    }
                    if (y > maxY) {
                        maxY = y;
                    }
                }
            }
        }
        this->maxXIndex.push_back(maxX);
        this->maxYIndex.push_back(maxY);
    }
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

int Tetromino::getMaxXIndex(int rotation) const {
    return this->maxXIndex[rotation];
}

int Tetromino::getMaxYIndex(int rotation) const {
    return this->maxYIndex[rotation];
}

void Tetromino::display() const {
    std::cout << "Tetromino: " << this->type << std::endl;
    for (int i = 0; i < this->rotations.size(); i++) {
        std::cout << "Rotation " << i << std::endl;
        this->rotations[i].display();
        std::cout << "Max X Index: " << this->maxXIndex[i] << std::endl;
        std::cout << "Max Y Index: " << this->maxYIndex[i] << std::endl;
    }
}