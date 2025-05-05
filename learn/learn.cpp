#include "test.h"
#include <iostream>
#include <sstream>

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Usage: xmake run learn <exercice number>" << std::endl;
        return EXIT_FAILURE;
    }

    std::stringstream ss;
    Log log{Console{}};

    ss << argv[1];
    log << ss.str();

    return EXIT_SUCCESS;
}
