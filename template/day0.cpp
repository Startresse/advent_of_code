#include "day0.h"

void Day0::run() {
    std::ifstream file;
    file.open("inputs/input_d0.txt");
    if (!file.is_open()) {
        std::cout << "couldn't open file" << std::endl;
        return;
    }

    file.close();
}