#include "constants/GameSpeed.h"
#include <stdexcept>

int getFramesPerDropForLevel(int level) {
    if (level < 18) throw std::invalid_argument("getGravityForLevel(int level): level must be at least 18");
    if (level == 18) return 3;
    else if (level < 29) return 2;
    else return 1;
}