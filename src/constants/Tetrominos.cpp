#include "models/Grid.h"
#include "models/Tetromino.h"
#include "constants/Tetrominos.h"
#include <initializer_list>

// all pieces are 4x4 and as top-left as possible

Tetromino I_PIECE = Tetromino(I_TYPE, {
    Grid<4, 4>({
        0b1111,
        0b0000,
        0b0000,
        0b0000
    }),
    Grid<4, 4>({
        0b1000,
        0b1000,
        0b1000,
        0b1000
    }),
});

Tetromino J_PIECE = Tetromino(J_TYPE, {
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

Tetromino L_PIECE = Tetromino(L_TYPE, {
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

Tetromino O_PIECE = Tetromino(O_TYPE, {
    Grid<4, 4>({
        0b1100,
        0b1100,
        0b0000,
        0b0000
    }),
});

Tetromino S_PIECE = Tetromino(S_TYPE, {
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

Tetromino T_PIECE = Tetromino(T_TYPE, {
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

Tetromino Z_PIECE = Tetromino(Z_TYPE, {
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