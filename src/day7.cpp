#include "day7.h"

void Day7::run() {
    std::ifstream file;
    file.open("inputs/input_d7.txt");
    if (!file.is_open()) {
        std::cout << "couldn't open file" << std::endl;
        return;
    }

    std::cout << "Day 7 OK!" << std::endl;

    file.close();
}