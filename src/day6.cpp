#include "day6.h"

void Day6::run() {
    std::ifstream file;
    file.open("inputs/input_d6.txt");
    if (!file.is_open()) {
        std::cout << "couldn't open file" << std::endl;
        return;
    }

    std::cout << "Day 6 OK!" << std::endl;

    file.close();
}