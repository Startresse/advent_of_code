#pragma once

#include <iostream>
#include <fstream>

class Day13 {
private:
    const char* filename = "inputs/input_d13.txt";

public:
    Day13(const int argc, const char** argv) {
        if (argc > 1)
            filename = argv[1];
    }

    void run();
};