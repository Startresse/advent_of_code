#include "day6.h"

void Day6::run() {
    std::ifstream file;
    file.open("inputs/input_d6.txt");
    if (!file.is_open()) {
        std::cout << "couldn't open file" << std::endl;
        return;
    }

    int res = 0;
    std::string line;
    while(getline(file, line)) {
        std::vector<bool> all_ok(26, true);
        do {
            std::vector<bool> letter(26, false);
            for (auto c : line) {
                letter[c - 'a'] = true;
            }
            for (uint i = 0; i < letter.size(); ++i) {
                all_ok[i] = all_ok[i] && letter[i];
            }

        } while(getline(file, line) && !line.empty());
        res += std::count(all_ok.begin(), all_ok.end(), true);

    }
    std::cout << res << std::endl;


    file.close();
}