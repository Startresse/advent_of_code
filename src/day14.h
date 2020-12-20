#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

class Day14 {
private:
    const char* filename = "inputs/input_d14.txt";

public:
    Day14(const int argc, const char** argv) {
        if (argc > 1)
            filename = argv[1];
    }

    void run();
};