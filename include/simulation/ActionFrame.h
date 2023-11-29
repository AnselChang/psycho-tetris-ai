#include <vector>
#include "constants/GameSpeed.h"
#include "simulation/InputSequence.h"

// a single frame for which an action can be taken and/or the piece drops due to gravity
struct ActionFrame {
    bool isInput;
    bool isDrop;
};

class ActionFrames {

private:
    std::vector<ActionFrame> frames;

public:
    ActionFrames(const InputSequence& sequence, int level);

    ActionFrame get(int index) const;
    int size() const;
    void display() const;

};