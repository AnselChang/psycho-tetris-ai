#ifndef TETRISBOARD_H
#define TETRISBOARD_H

#include <bitset>
#include <array>
#include <initializer_list>
#include <vector>

class TetrisBoard {
private:
    static const int width = 10;
    static const int height = 20;
    std::array<std::bitset<width>, height> rows;

public:

    // constructor that takes in a list of rows
    TetrisBoard();
    TetrisBoard(std::initializer_list<std::bitset<width>> rows);


    void set(int x, int y, bool value);
    bool get(int x, int y) const;
    void display() const;
};

#endif // TETRISBOARD_H