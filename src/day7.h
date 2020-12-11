#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <algorithm>

class Day7 {
    private:
        const char* filename = "inputs/input_d7.txt";

        std::map<std::string, std::vector<std::string>> parents;
        std::map<std::string, std::vector<std::pair<std::string, int>>> childs;

    public:
        Day7(const int argc, const char** argv) {
            if (argc > 1)
                filename = argv[1];
        }

        void run();
};