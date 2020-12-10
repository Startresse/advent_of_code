#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>

class Day10 {
    private:
        const char* filename = "inputs/input_d10.txt";

        std::vector<int> values;
        std::map<int, long long> dp_map;

    public:
        Day10(const int argc, const char** argv) {
            if (argc > 1)
                filename = argv[1];
        }

        void run();

        long long dp(int);
};