#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

enum tile {
    EMPTY,
    TAKEN,
    FLOOR
};

class Day11 {
private:
    const char* filename = "inputs/input_d11.txt";

public:
    Day11(const int argc, const char** argv) {
        if (argc > 1)
            filename = argv[1];
    }

    void run();
};