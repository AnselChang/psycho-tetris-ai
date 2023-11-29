#ifndef TETRIS_AI_ACTIONFRAME_H
#define TETRIS_AI_ACTIONFRAME_H

#include <vector>
#include "constants/GameSpeed.h"
#include "simulation/InputSequence.h"

enum Action {
    INPUT,
    DROP
};

// a single frame for which an action can be taken and/or the piece drops due to gravity
struct ActionFrame {
    int frameIndex;
    Action action;
};

class ActionFrames {

private:
    std::vector<ActionFrame> frames;

public:
    ActionFrames(const InputSequence& sequence, int level);

    ActionFrame get(int index) const; // get ActionFrame index (not frame index)
    int size() const;
    void display() const;

};

#endif //TETRIS_AI_ACTIONFRAME_H