#include "simulation/ActionFrame.h"
#include "constants/GameSpeed.h"
#include <stdexcept>
#include <iostream>

ActionFrames::ActionFrames(const InputSequence& sequence, int level) {

    const int framesPerDrop = getFramesPerDropForLevel(level);

    for (int i = 0; i < framesPerDrop * 20; i++) {
        const bool isInput = sequence.get(i);
        const bool isDrop = i % framesPerDrop == 0;

        // only save frames that do something
        if (isInput || isDrop) this->frames.push_back({isInput, isDrop});
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
        std::cout << (frame.isInput ? "Input" : "") << " " << (frame.isDrop ? "Drop" : "") << std::endl;
    }
}