#ifndef TETRISBOARD_H
#define TETRISBOARD_H

#include <bitset>
#include <array>

class TetrisBoard {
private:
    static const int width = 10;
    static const int height = 20;
    std::array<std::bitset<width>, height> rows;

public:
    void set(int x, int y, bool value);
    bool get(int x, int y) const;
    void display() const;
};

#endif // TETRISBOARD_H