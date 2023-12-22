#include "http/ExtractQueryParams.h"
#include "http/json.hpp"

TetrominoType getTetrominoTypeFromString(const std::string& s) {
    if (s == "I") {
        return TetrominoType::I_TYPE;
    } else if (s == "J") {
        return TetrominoType::J_TYPE;
    } else if (s == "L") {
        return TetrominoType::L_TYPE;
    } else if (s == "O") {
        return TetrominoType::O_TYPE;
    } else if (s == "S") {
        return TetrominoType::S_TYPE;
    } else if (s == "T") {
        return TetrominoType::T_TYPE;
    } else if (s == "Z") {
        return TetrominoType::Z_TYPE;
    } else {
        throw std::runtime_error("Invalid tetromino type string: " + s);
    }
}

int getNonnegativeNumberFromString(const std::string& s) {
    try {
        int number = std::stoi(s);
        if (number < 0) {
            throw std::runtime_error("Invalid level string. Must be nonegative: " + s);
        }
        return number;
    } catch (const std::exception& e) {
        throw std::runtime_error("Invalid level string. Must be a number: " + s);
    }
}

// make sure string only consists of X and ., and strip whitespace
std::string validateInputFrameTimeline(std::string s) {
    std::string strippedString = "";
    for (char c : s) {
        if (c == 'X' || c == '.') {
            strippedString += c;
        }
    }

    // string must contain at least one X and at least one .
    if (strippedString.find('X') == std::string::npos || strippedString.find('.') == std::string::npos) {
        throw std::runtime_error("Invalid inputFrameTimeline string. Must contain at least one X and at least one .: " + s);
    }

    return strippedString;
}

BoardState extractQueryParams(const httplib::Request& req) {

    std::cout << "Extracting query params" << std::endl;

    // Initialize default string values for parameters.
    std::string boardString = ""; // default empty board
    std::string currentPieceString = "";
    std::string nextPieceString = "";
    std::string levelString = "18"; // default level 18
    std::string linesString = "0";
    std::string inputFrameTimelineString = "X."; // default 30hz

    // Check if query parameters exist and assign them.
    if (req.has_param("board")) {
        boardString = req.get_param_value("board");
    }
    if (req.has_param("currentPiece")) {
        currentPieceString = req.get_param_value("currentPiece");
    }
    if (req.has_param("nextPiece")) {
        nextPieceString = req.get_param_value("nextPiece");
    }
    if (req.has_param("level")) {
        levelString = req.get_param_value("level");
    }
    if (req.has_param("lines")) {
        linesString = req.get_param_value("lines");
    }
    if (req.has_param("inputFrameTimeline")) {
        inputFrameTimelineString = req.get_param_value("inputFrameTimeline");
    }

    std::cout << "boardString: " << boardString << std::endl;
    std::cout << "currentPieceString: " << currentPieceString << std::endl;
    std::cout << "nextPieceString: " << nextPieceString << std::endl;
    std::cout << "levelString: " << levelString << std::endl;
    std::cout << "linesString: " << linesString << std::endl;
    std::cout << "inputFrameTimelineString: " << inputFrameTimelineString << std::endl;

    Grid<10,20> g(boardString);
    TetrisBoard board(g);

    board.display();

    TetrominoType currentType = getTetrominoTypeFromString(currentPieceString);
    TetrominoType nextType = getTetrominoTypeFromString(nextPieceString);

    std::cout << "currentType: " << currentType << std::endl;
    std::cout << "nextType: " << nextType << std::endl;

    int level = getNonnegativeNumberFromString(levelString);
    int lines = getNonnegativeNumberFromString(linesString);

    std::cout << "level: " << level << std::endl;
    std::cout << "lines: " << lines << std::endl;

    std::string inputFrameTimeline = validateInputFrameTimeline(inputFrameTimelineString);

    std::cout << "inputFrameTimeline: " << inputFrameTimeline << std::endl;

    return BoardState{board, currentType, nextType, level, lines, inputFrameTimeline};
}