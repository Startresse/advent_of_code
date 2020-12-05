#include "day1.h"

void Day1::run() {
    std::ifstream file;
    file.open("inputs/input_d1.txt");
    if (!file.is_open()) {
        std::cout << "couldn't open file" << std::endl;
        return;
    }

    std::vector<int> values;
    int value;
    while(file >> value)
        values.push_back(value);

    for (uint i = 0; i < values.size(); ++i) {
        for (uint j = 0; j < values.size(); ++j) {
            for (uint k = 0; k < values.size(); ++k) {
                if (i == j || j == k || i == k)
                    continue;

                if (values[i] + values[j] + values[k] == 2020) {
                    std::cout << values[i] * values[j] * values[k] << std::endl;
                    goto quit_loop;
                }

            }
        }
    }
    quit_loop:

    file.close();
}