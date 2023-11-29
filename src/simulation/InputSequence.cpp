#include "simulation/InputSequence.h"
#include <stdexcept>

InputSequence::InputSequence(std::vector<bool> sequence) {
    this->sequence = sequence;
}

// string sequence in the form "X..X..", etc
InputSequence::InputSequence(std::string stringSequence) {
    for (char c : stringSequence) {
        if (c == '.') {
            this->sequence.push_back(false);
        } else if (c == 'X') {
            this->sequence.push_back(true);
        } else {
            throw std::invalid_argument("InputSequence::InputSequence(std::string stringSequence): stringSequence must only contain 0s and 1s");
        }
    }
}

// return whether an input can be registered at the given index. if the index is out of bounds, modulo wraparound
bool InputSequence::get(int index) const {
    return this->sequence[index % this->sequence.size()];
}