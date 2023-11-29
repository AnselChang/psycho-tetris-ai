#include "models/Grid.h"
#include "models/Tetromino.h"
#include "constants/Tetrominos.h"
#include <initializer_list>

// all pieces are represented as 4x4 and as top-left as possible
// HOWEVER, since the leftmost column is the least significant bit, the pieces are actually
// defined 4x4 to the and mirrored horizontally here

Tetromino I_PIECE(I_TYPE, {
    Grid<4, 4>({
        0b0000,
        0b1111,
        0b0000,
        0b0000
    }),
    Grid<4, 4>({
        0b0100,
        0b0100,
        0b0100,
        0b0100
    }),
}, 3);

Tetromino J_PIECE(J_TYPE, {
    Grid<4, 4>({
        0b0111,
        0b0100,
        0b0000,
        0b0000
    }),
    Grid<4, 4>({
        0b0010,
        0b0010,
        0b0011,
        0b0000
    }),
    Grid<4, 4>({
        0b0001,
        0b0111,
        0b0000,
        0b0000
    }),
    Grid<4, 4>({
        0b0011,
        0b0001,
        0b0001,
        0b0000
    }),
}, 4);

Tetromino L_PIECE(L_TYPE, {
    Grid<4, 4>({
        0b0111,
        0b0001,
        0b0000,
        0b0000
    }),
    Grid<4, 4>({
        0b0011,
        0b0010,
        0b0010,
        0b0000
    }),
    Grid<4, 4>({
        0b0100,
        0b0111,
        0b0000,
        0b0000
    }),
    Grid<4, 4>({
        0b0001,
        0b0001,
        0b0011,
        0b0000
    }),
}, 4);

Tetromino O_PIECE(O_TYPE, {
    Grid<4, 4>({
        0b0011,
        0b0011,
        0b0000,
        0b0000
    }),
}, 4);

Tetromino S_PIECE(S_TYPE, {
    Grid<4, 4>({
        0b0110,
        0b0011,
        0b0000,
        0b0000
    }),
    Grid<4, 4>({
        0b0001,
        0b0011,
        0b0010,
        0b0000
    }),
}, 4);

Tetromino T_PIECE(T_TYPE, {
    Grid<4, 4>({
        0b0111,
        0b0010,
        0b0000,
        0b0000
    }),
    Grid<4, 4>({
        0b0010,
        0b0011,
        0b0010,
        0b0000
    }),
    Grid<4, 4>({
        0b0010,
        0b0111,
        0b0000,
        0b0000
    }),
    Grid<4, 4>({
        0b0001,
        0b0011,
        0b0001,
        0b0000
    }),
}, 4);

Tetromino Z_PIECE(Z_TYPE, {
    Grid<4, 4>({
        0b0011,
        0b0110,
        0b0000,
        0b0000
    }),
    Grid<4, 4>({
        0b0010,
        0b0011,
        0b0001,
        0b0000
    }),
}, 4);

std::map<TetrominoType, Tetromino> TETROMINOS = {
    {I_TYPE, I_PIECE},
    {J_TYPE, J_PIECE},
    {L_TYPE, L_PIECE},
    {O_TYPE, O_PIECE},
    {S_TYPE, S_PIECE},
    {T_TYPE, T_PIECE},
    {Z_TYPE, Z_PIECE}
};

std::map<TetrominoType, std::string> TETROMINO_NAMES = {
    {I_TYPE, "I"},
    {J_TYPE, "J"},
    {L_TYPE, "L"},
    {O_TYPE, "O"},
    {S_TYPE, "S"},
    {T_TYPE, "T"},
    {Z_TYPE, "Z"}
};