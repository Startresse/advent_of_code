#include "day4.h"

void Day4::run() {

    std::ifstream file;
    file.open("inputs/input_d4.txt");
    if (!file.is_open()) {
        std::cout << "couldn't open file" << std::endl;
        return;
    }

    std::cout << "Hello world" << std::endl;
    file.close();

}