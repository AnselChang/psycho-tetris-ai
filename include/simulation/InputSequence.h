#include <vector>
#include <string>

// stores a sequence of whether inputs can be registered for that frame
class InputSequence {

private:
    std::vector<bool> sequence;

public:
    InputSequence(std::vector<bool> sequence);
    InputSequence(std::string stringSequence);

    bool get(int index) const;

};