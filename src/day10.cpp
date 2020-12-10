#include "day10.h"



void Day10::run() {
    std::ifstream file;
    file.open("inputs/input_d10.txt");
    if (!file.is_open()) {
        std::cout << "couldn't open file" << std::endl;
        return;
    }

    std::vector<int> input;
    int value;
    while(file >> value)
        input.push_back(value);
    file.close();


    std::sort(input.begin(), input.end());

    // int current_jolt = 0;
    // int one_diff = 0;
    // int three_diff = 1;
    // for (auto x : input) {
    //     if (x > current_jolt + 3)
    //         break;

    //     if (x - current_jolt == 3)
    //         three_diff++;

    //     if (x - current_jolt == 1)
    //         one_diff++;
        
    //     current_jolt = x;
    // }
    // std::cout << three_diff * one_diff << std::endl;


    double nb_way = 0;
    for (int i = 0; i < 3; ++i){
        if (input[i] <= 3)
            nb_way++;
    }
    for (int i = 0; i < input.size(); ++i) {
        int valid_next = 0;
        for (int j = 0; j < std::min<uint>(3u, input.size() - i); ++j) { //
            if (input[i + j] - input[i] <= 3){
                valid_next++;
            }
        }
        nb_way *= valid_next;
    }
    std::cout << (long long )nb_way << std::endl;
    
}