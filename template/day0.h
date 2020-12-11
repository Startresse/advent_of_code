#pragma once

#include <iostream>
#include <fstream>

class Day0 {
private:
    const char* filename = "inputs/input_d0.txt";

public:
    Day0(const int argc, const char** argv) {
        if (argc > 1)
            filename = argv[1];
    }

    void run();
};