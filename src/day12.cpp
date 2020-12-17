#include "day12.h"


cadran_dir c2d(char l) {
    if (l == 'N') return NORTH;
    if (l == 'S') return SOUTH;
    if (l == 'E') return EAST;
    if (l == 'W') return WEST;
    exit(1);
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
            s.mv_wp(val, c2d(L));
            break;
        }
    }
    std::cout << s.dist() << std::endl;

    file.close();
}

void Ship::go(int v) {
    x += v * way_x;
    y += v * way_y;
}

void Ship::turn(dir d) {
    int _x = way_x;
    int _y = way_y;
    if (d == LEFT) {
        way_x = -_y;
        way_y = _x;
    }
    if (d == RIGHT) {
        way_x = _y;
        way_y = -_x;
    }
}


void Ship::mv_wp(int v, cadran_dir d)
{
    switch (d)
    {
    case NORTH:
        way_y += v;
        break;
    case EAST:
        way_x += v;
        break;
    case SOUTH:
        way_y -= v;
        break;
    case WEST:
        way_x -= v;
        break;
    
    default:
        break;
    }
}


