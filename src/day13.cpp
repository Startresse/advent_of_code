#include "day13.h"

void Day13::run() {
    std::ifstream file;
    file.open(filename);
    if (!file.is_open()) {
        std::cout << "couldn't open file" << std::endl;
        return;
    }

    std::cout << "Day 13 OK!" << std::endl;

    file.close();
}