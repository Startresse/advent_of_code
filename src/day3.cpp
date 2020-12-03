#include "day3.h"

void Day3::run() {
    int res = 1.0;

    std::vector<std::pair<int, int>> params;
    params.push_back(std::make_pair(1, 1));
    params.push_back(std::make_pair(3, 1));
    params.push_back(std::make_pair(5, 1));
    params.push_back(std::make_pair(7, 1));
    params.push_back(std::make_pair(1, 2));
    for (auto p : params) {

        std::ifstream file;
        file.open("inputs/input_d3.txt");

        std::string line;
        int x = 0;
        int y = p.second;
        int count = 0;
        while (file >> line) {
            int size = line.size();

            if (line[x] == '#')
                count++;
            x += p.first;
            x %= size;
            for(int i = 1; i < y; ++i)
                file >> line;
        }
        res *= count;
        std::cout << count << std::endl;
        file.close();
    }
    std::cout << res << std::endl;

}