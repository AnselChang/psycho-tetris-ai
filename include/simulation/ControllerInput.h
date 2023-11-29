enum RotationInput {
    ROTATION_NONE,
    ROTATION_LEFT,
    ROTATION_RIGHT
};

enum TranslationInput {
    TRANSLATION_NONE,
    TRANSLATION_LEFT,
    TRANSLATION_RIGHT,
};

// controller input for a single frame
struct ControllerInput {
    RotationInput rotationInput;
    TranslationInput translationInput;
};