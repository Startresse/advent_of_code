#include "day7.h"

void Day7::run() {
    std::ifstream file;
    file.open("inputs/input_d7.txt");
    if (!file.is_open()) {
        std::cout << "couldn't open file" << std::endl;
        return;
    }

    std::map<std::string, std::string> contained;
    std::map<std::string, std::pair<std::string, int>> contains;

    file.close();
}