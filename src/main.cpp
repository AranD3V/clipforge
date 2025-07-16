#include "cli_parser.h"
#include "processor.h"
#include <iostream>

int main(int argc, char* argv[]) {
    try {
        auto args = parseArgs(argc, argv);
        processMedia(args);
    }
    catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << std::endl;
        return 1;
    }
    return 0;
}
