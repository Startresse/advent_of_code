#pragma once

#include <iostream>
#include <fstream>

class Day12 {
private:
    const char* filename = "inputs/input_d12.txt";

public:
    Day12(const int argc, const char** argv) {
        if (argc > 1)
            filename = argv[1];
    }

    void run();
};


enum cadran_dir {NORTH, EAST, SOUTH, WEST};
enum dir {LEFT = 3, FORWARD = 0, RIGHT = 1};
class Ship {
private:
    cadran_dir direction;
    int x;
    int y;

public:
    Ship() {
        direction = EAST;
        x = 0;
        y = 0;
    }

    void turn(dir d) {
        direction = cadran_dir((direction + d) % 4);
    }

    void go(int v);
    void go(int v, cadran_dir d);

    int dist() {return abs(x) + abs(y);}

};