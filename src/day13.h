#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <cassert>
#include <boost/integer/mod_inverse.hpp>

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