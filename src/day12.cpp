#include "day12.h"

cadran_dir c2d(char l) {
    if (l == 'N') return NORTH;
    if (l == 'S') return SOUTH;
    if (l == 'E') return EAST;
    if (l == 'W') return WEST;
}

void Day12::run() {
    std::ifstream file;
    file.open(filename);
    if (!file.is_open()) {
        std::cout << "couldn't open file" << std::endl;
        return;
    }

    Ship s;
    char L;
    int val;
    while(file >> L >> val) {
        switch (L)
        {
        case 'F':
            s.go(val);
            break;
        case 'L':
            while(val > 0) {
                s.turn(LEFT);
                val -= 90;
            }
            break;
        case 'R':
            while(val > 0) {
                s.turn(RIGHT);
                val -= 90;
            }
            break;
        
        default:
            s.go(val, c2d(L));
            break;
        }
    }
    std::cout << s.dist() << std::endl;

    file.close();
}

void Ship::go(int v) {
    go(v, direction);
}

void Ship::go(int v, cadran_dir d)
{
    switch (d)
    {
    case NORTH:
        y += v;
        break;
    case EAST:
        x += v;
        break;
    case SOUTH:
        y -= v;
        break;
    case WEST:
        x -= v;
        break;
    
    default:
        break;
    }
}


