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

        std::string target = "shinygoldbag";

        std::map<std::string, std::vector<std::pair<std::string, int>>> contains;

    public:
        Day7(const int argc, const char** argv) {
            if (argc > 1)
                filename = argv[1];
        }

        bool contain(std::string parent);
        int count_bags(std::string);


        bool found(std::string);
        void run();
};