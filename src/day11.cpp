#include "day11.h"

tile convert(const char c) {
    if (c == 'L')
        return EMPTY;
    if (c == '#')
        return TAKEN;
    if (c == '.')
        return FLOOR;
    std::cout << "reading issue" << std::endl;
    exit(1);
}

void display_grid(std::vector<std::vector<tile>> grid) {
    for (auto line : grid) {
        for (auto tile : line) {
            switch (tile)
            {
            case EMPTY:
                std::cout << 'L';
                break;
            case TAKEN:
                std::cout << '#';
                break;
            case FLOOR:
                std::cout << '.';
                break;
            default:
                break;
            }
        }
        std::cout << std::endl;
    }
}

int count_occupied(const std::vector<std::vector<tile>>& grid) {
    int res = 0;
    for (auto x : grid) {
        for (auto y : x) {
            if (y == TAKEN)
                res++;
        }
    }
    return res;
}

// return false is nothing changed;
bool update(std::vector<std::vector<tile>>& grid) {
    bool change = false;
    std::vector<std::vector<tile>> grid_fixed(grid);

    for (int i = 0; i < (int) grid.size(); ++i) {
        for (int j = 0; j < (int) grid[i].size(); ++j) {
            int nocc = 0;                    
            for (int ii = -1; ii <= 1; ++ii) {
                for (int jj = -1; jj <=1; ++jj) {

                    if (ii == 0 && jj == 0)
                        continue;

                    int ni = i + ii;
                    int nj = j + jj;
                    if (ni < 0 || ni >= (int) grid.size() || nj < 0 || nj >= (int) grid[0].size())
                        continue;

                    if (grid_fixed[ni][nj] == TAKEN) {
                        ++nocc;
                    }

                }
            }
            if (grid[i][j] == TAKEN && nocc >= 4) {
                grid[i][j] = EMPTY;
                change = true;
            } else if (grid[i][j] == EMPTY && nocc == 0) {
                grid[i][j] = TAKEN;
                change = true;
            }

        }
    }

    return change;
}

bool update_2(std::vector<std::vector<tile>>& grid) {
    bool change = false;
    std::vector<std::vector<tile>> grid_fixed(grid);

    for (int i = 0; i < (int) grid.size(); ++i) {
        for (int j = 0; j < (int) grid[i].size(); ++j) {
            int nocc = 0;                    
            for (int ii = -1; ii <= 1; ++ii) {
                for (int jj = -1; jj <=1; ++jj) {

                    if (ii == 0 && jj == 0)
                        continue;

                    int ni = i;
                    int nj = j;
                    do {
                        ni = ni + ii;
                        nj = nj + jj;
                    } while (ni >= 0 &&
                             nj >= 0 &&
                             ni < (int) grid.size() &&
                             nj < (int) grid[0].size() &&
                             grid_fixed[ni][nj] == FLOOR);

                    if (ni < 0 || ni >= (int) grid.size() || nj < 0 || nj >= (int) grid[0].size())
                        continue;

                    if (grid_fixed[ni][nj] == TAKEN) {
                        ++nocc;
                    }

                }
            }
            if (grid[i][j] == TAKEN && nocc >= 5) {
                grid[i][j] = EMPTY;
                change = true;
            } else if (grid[i][j] == EMPTY && nocc == 0) {
                grid[i][j] = TAKEN;
                change = true;
            }

        }
    }

    return change;

}

void Day11::run() {
    std::ifstream file;
    file.open(filename);
    if (!file.is_open()) {
        std::cout << "couldn't open file" << std::endl;
        return;
    }

    std::string line;
    int nb_lines = 0;
    while(file >> line)
        nb_lines++;

    file.clear();
    file.seekg(0);

    std::vector<std::vector<tile>> grid;
    grid.resize(nb_lines, std::vector<tile>());

    int line_id = 0;
    while (file >> line) {
        for (auto c : line) {
            grid[line_id].push_back(convert(c));
        }
        ++line_id;
    }
    file.close();

    while(update_2(grid));
    std::cout << count_occupied(grid) << std::endl;

}