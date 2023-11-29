#include "models/Grid.h"
#include "models/Tetromino.h"
#include "constants/Tetrominos.h"
#include <initializer_list>

// all pieces are represented as 4x4 and as top-left as possible
// HOWEVER, since the leftmost column is the least significant bit, the pieces are actually
// defined 4x4 to the and mirrored horizontally here

Tetromino I_PIECE(I_TYPE, {
    Grid<4, 4>({
        0b1111,
        0b0000,
        0b0000,
        0b0000
    }),
    Grid<4, 4>({
        0b0001,
        0b0001,
        0b0001,
        0b0001
    }),
});

Tetromino J_PIECE(J_TYPE, {
    Grid<4, 4>({
        0b1000,
        0b1110,
        0b0000,
        0b0000
    }),
    Grid<4, 4>({
        0b0110,
        0b0100,
        0b0100,
        0b0000
    }),
    Grid<4, 4>({
        0b0000,
        0b1110,
        0b0010,
        0b0000
    }),
    Grid<4, 4>({
        0b0100,
        0b0100,
        0b1100,
        0b0000
    }),
});

Tetromino L_PIECE(L_TYPE, {
    Grid<4, 4>({
        0b0010,
        0b1110,
        0b0000,
        0b0000
    }),
    Grid<4, 4>({
        0b0100,
        0b0100,
        0b0110,
        0b0000
    }),
    Grid<4, 4>({
        0b0000,
        0b1110,
        0b1000,
        0b0000
    }),
    Grid<4, 4>({
        0b1100,
        0b0100,
        0b0100,
        0b0000
    }),
});

Tetromino O_PIECE(O_TYPE, {
    Grid<4, 4>({
        0b1100,
        0b1100,
        0b0000,
        0b0000
    }),
});

Tetromino S_PIECE(S_TYPE, {
    Grid<4, 4>({
        0b0110,
        0b1100,
        0b0000,
        0b0000
    }),
    Grid<4, 4>({
        0b0100,
        0b0110,
        0b0010,
        0b0000
    }),
});

Tetromino T_PIECE(T_TYPE, {
    Grid<4, 4>({
        0b0100,
        0b1110,
        0b0000,
        0b0000
    }),
    Grid<4, 4>({
        0b0100,
        0b0110,
        0b0100,
        0b0000
    }),
    Grid<4, 4>({
        0b0000,
        0b1110,
        0b0100,
        0b0000
    }),
    Grid<4, 4>({
        0b0100,
        0b1100,
        0b0100,
        0b0000
    }),
});

Tetromino Z_PIECE(Z_TYPE, {
    Grid<4, 4>({
        0b1100,
        0b0110,
        0b0000,
        0b0000
    }),
    Grid<4, 4>({
        0b0010,
        0b0110,
        0b0100,
        0b0000
    }),
});

std::map<TetrominoType, Tetromino> tetrominoMap = {
    {I_TYPE, I_PIECE},
    {J_TYPE, J_PIECE},
    {L_TYPE, L_PIECE},
    {O_TYPE, O_PIECE},
    {S_TYPE, S_PIECE},
    {T_TYPE, T_PIECE},
    {Z_TYPE, Z_PIECE}
};