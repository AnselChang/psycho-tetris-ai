#include <iostream>
#include "models/TetrisBoard.h"
#include "constants/Tetrominos.h"
#include "constants/TetrominoType.h"
#include "models/MoveableTetromino.h"
#include "simulation/ActionFrame.h"
#include "simulation/MoveGeneration.h"
#include "search/TwoPieceSearch.h"

// #define CPPHTTPLIB_OPENSSL_SUPPORT
#include <cstdlib> 
#include "http/json.hpp"
#include "http/httplib.h"

using json = nlohmann::json;


#include <chrono>
using namespace std::chrono;

void testMoveGeneration() {

    TetrisBoard board;
    // randomize bottom rows
    for (int y = 15; y < 20; y++) {
        for (int x = 0; x < 10; x++) {
            board.getGrid().set(x, y, rand() % 7);
        }
    }

    std::cout << "NEW GENERATION" << std::endl;
    board.display();

    ActionFrames af(InputSequence("X."), 18);

    auto start = high_resolution_clock::now();
    std::vector<MoveableTetromino> moves = generateMoves(board, af, TetrominoType::T_TYPE);
    auto stop = high_resolution_clock::now();

    // std::cout << "_______" << std::endl;
    // for (MoveableTetromino mt : moves) {
    //     board.displayWithPiece(mt);
    //     // board.displayWithPiece();
    // }
    auto duration = duration_cast<microseconds>(stop - start);
    std::cout << "Time taken by function: " << duration.count() << " microseconds" << std::endl;
    std::cout << "Number of moves: " << moves.size() << std::endl;


}
void testSearch() {

    TetrisBoard board;
    for (int y = 15; y < 20; y++) {
        for (int x = 0; x < 10; x++) {
            board.getGrid().set(x, y, rand() %6 );
        }
    }

    TwoPieceSearch search(TetrominoType::J_TYPE, TetrominoType::T_TYPE, board, InputSequence("X...."), 18);

    auto start = high_resolution_clock::now();
    search.search();
    auto stop = high_resolution_clock::now();

    search.display();
    std::cout << "Number of placements: " << search.getNumPlacements() << std::endl;

    auto duration = duration_cast<milliseconds>(stop - start);
    std::cout << "Time taken by function: " << duration.count() << " milliseconds" << std::endl;

}

void testActionFrame() {
    ActionFrames af(InputSequence("X."), 18);
    af.display();
}

int getPort() {
    // Get the PORT environment variable
    char* port_env = std::getenv("PORT");
    
    // Convert PORT from string to an integer
    int port = 0;
    if (port_env != nullptr) {
        port = std::atoi(port_env);
    } else {
        std::cerr << "PORT environment variable not set. Using a default value." << std::endl;
        port = 8080; // default port if not set
    }

    return port;
}

void testHTTPServer() {

    // HTTP
    httplib::Server svr;

    // // HTTPS
    // httplib::SSLServer svr;

    svr.Get("/hi", [](const httplib::Request &, httplib::Response &res) {
        std::cout << "GET /hi" << std::endl;
        res.set_content("Hello World!", "text/plain");
    });

    svr.Get("/sum", [&](const httplib::Request& req, httplib::Response& res) {

        std::cout << "GET /sum" << std::endl;

        // Initialize a and b with default values.
        std::string a = "0";
        std::string b = "0";

        // Check if query parameters exist and assign them.
        if (req.has_param("a")) {
            a = req.get_param_value("a");
            std::cout << "a: " << a << std::endl;
        }
        if (req.has_param("b")) {
            b = req.get_param_value("b");
            std::cout << "b: " << b << std::endl;
        }

        // Create a JSON object containing a and b.
        json response_json = {
            {"a", a},
            {"b", b}
        };

        // Set the response content type to application/json and send the JSON as a string.
        res.set_content(response_json.dump(), "application/json");
    });

    const int port = getPort();
    std::cout << "Starting server on port " << port << std::endl;

    svr.listen("0.0.0.0", port);
}

int main() {

    testHTTPServer();

    //testSearch();
    //testMoveGeneration();
    //testActionFrame();


    // MoveableTetromino mt(TetrominoType::T_TYPE, 0, 5, 6);
    // TetrisBoard board;

    // board.displayWithPiece(mt);

    

    return 0;
}