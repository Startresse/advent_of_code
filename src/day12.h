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

    int way_x;
    int way_y;

public:
    Ship() {
        direction = EAST;
        x = 0;
        y = 0;
        way_x = 10;
        way_y = 1;
    }

    void turn(dir d);

    void go(int v);
    void mv_wp(int v, cadran_dir d);

    int dist() {return abs(x) + abs(y);}

    friend std::ostream& operator<<(std::ostream& os, const Ship& s);

};

std::ostream& operator<<(std::ostream& os, const Ship& s) {
    os << "Ship pos : (" << s.x << ", " << s.y << ") | Ship wp (" << s.way_x << ", " << s.way_y << ")";
    return os;
}