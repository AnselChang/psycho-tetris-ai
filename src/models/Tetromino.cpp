#include "models/Tetromino.h"
#include "models/Grid.h"

Tetromino::Tetromino():
    type(UNDEFINED_TYPE), spawnX(0), spawnY(0)
{}

Tetromino::Tetromino(TetrominoType type, std::vector<Grid<4,4>> rotations, int spawnX, int spawnY):
spawnX(spawnX), spawnY(spawnY) {


    this->type = type;
    this->rotations = rotations;

    // std::cout << "Tetromino: " << type << std::endl;

    // calculate the max x and y indices for each rotation
    for (size_t i = 0; i < rotations.size(); i++) {
        int maxX = 0;
        int maxY = 0;
        int minX = 3;
        int minY = 3;
        for (int y = 0; y < 4; y++) {
            for (int x = 0; x < 4; x++) {         
                if (rotations[i].get(x, y)) {
                    if (x > maxX) {
                        maxX = x;
                    }
                    if (y > maxY) {
                        maxY = y;
                    }
                    if (x < minX) {
                        minX = x;
                    }
                    if (y < minY) {
                        minY = y;
                    }
                }
            }
            
        }
        this->maxXIndex.push_back(maxX);
        this->maxYIndex.push_back(maxY);
        this->minXIndex.push_back(minX);
        this->minYIndex.push_back(minY);
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

int Tetromino::getMinXIndex(int rotation) const {
    return this->minXIndex[rotation];
}

int Tetromino::getMinYIndex(int rotation) const {
    return this->minYIndex[rotation];
}

int Tetromino::getMaxXIndex(int rotation) const {
    return this->maxXIndex[rotation];
}

int Tetromino::getMaxYIndex(int rotation) const {
    return this->maxYIndex[rotation];
}

int Tetromino::getSpawnX() const {
    return this->spawnX;
}

int Tetromino::getSpawnY() const {
    return this->spawnY;
}

void Tetromino::display() const {
    std::cout << "Tetromino: " << this->type << std::endl;
    for (size_t i = 0; i < this->rotations.size(); i++) {
        std::cout << "Rotation " << i << std::endl;
        this->rotations[i].display();
        std::cout << "Max X Index: " << this->maxXIndex[i] << std::endl;
        std::cout << "Max Y Index: " << this->maxYIndex[i] << std::endl;
    }
}