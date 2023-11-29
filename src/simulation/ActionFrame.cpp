#include "simulation/ActionFrame.h"
#include "constants/GameSpeed.h"
#include <stdexcept>
#include <iostream>

ActionFrames::ActionFrames(const InputSequence& sequence, int level) {

    const int framesPerDrop = getFramesPerDropForLevel(level);

    // push input and drop actions in the order they are supposed to be processed
    // if both input and drop at the same time, input is processed before drop
    for (int i = 0; i < framesPerDrop * 20; i++) {
        const bool isInput = sequence.get(i);
        const bool isDrop = i % framesPerDrop == 0;

        if (isInput && isDrop) {
            this->frames.push_back({i, INPUT});
            this->frames.push_back({i, DROP});
        } else if (isInput) {
            this->frames.push_back({i, INPUT});
        } else if (isDrop) {
            this->frames.push_back({i, DROP});
        }
    }
}

ActionFrame ActionFrames::get(int index) const {
    if (index < 0 || index >= this->frames.size()) throw std::invalid_argument("ActionFrames::get(int index): index out of bounds");
    return this->frames[index];
}

int ActionFrames::size() const {
    return this->frames.size();
}

void ActionFrames::display() const {
    for (ActionFrame frame : this->frames) {
        std::cout << (frame.action == Action::INPUT ? "Input" : "Drop") << std::endl;
    }
}