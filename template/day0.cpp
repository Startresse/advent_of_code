#include "day0.h"

void Day0::run() {
    std::ifstream file;
    file.open(filename);
    if (!file.is_open()) {
        std::cout << "couldn't open file" << std::endl;
        return;
    }

    std::cout << "Day 0 OK!" << std::endl;

    file.close();
}