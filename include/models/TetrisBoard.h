#ifndef TETRISBOARD_H
#define TETRISBOARD_H

#include <bitset>
#include <array>
#include <initializer_list>
#include <vector>
#include <optional>
#include "models/Grid.h"
#include "models/MoveableTetromino.h"

class MoveableTetromino;

class TetrisBoard {
private:
    static const int width = 10;
    static const int height = 20;

    Grid<width, height> grid;

public:

    // constructor that takes in a list of rows
    TetrisBoard() = default;
    TetrisBoard(Grid<width, height> grid);


    Grid<width, height>& getGrid();
    std::bitset<width> getRow(int y) const;
    bool get(int x, int y) const;
    void display() const;
    void displayWithPiece(std::optional<MoveableTetromino> mt = {}, std::optional<MoveableTetromino> mt2 = {}) const;

    // run any line clears and return the number of lines cleared
    int clearLines();
    
};

#endif // TETRISBOARD_H