#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <map>

#define LENGTH 36

enum tril {FALSE, TRUE, NONE = -1};
typedef std::vector<tril> mask;
typedef std::vector<bool> integer;

class Day14 {
private:
    const char* filename = "inputs/input_d14.txt";

public:
    Day14(const int argc, const char** argv) {
        if (argc > 1)
            filename = argv[1];
    }

    void run();
};

template <typename T>
void display(std::vector<T> v) {
    for (auto a : v) {
        std::cout << a << ", ";
    }
    std::cout << "\b\b  " << std::endl;
}