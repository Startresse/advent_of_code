#include "day8.h"

void Day8::run() {
    std::ifstream file;
    file.open("inputs/input_d8.txt");
    if (!file.is_open()) {
        std::cout << "couldn't open file" << std::endl;
        return;
    }

    std::vector<std::string> lines;
    lines.clear();
    std::string line;
    while(getline(file, line))
        lines.push_back(line);
    file.close();

    for (uint it = 0; it < lines.size(); ++it) {
        std::vector<std::string> new_lines(lines);
        std::string instru = new_lines[it].substr(0, 3);
        if (instru == "jmp") {
            new_lines[it].replace(0, 3, "nop");
        } else if (instru == "nop") {
            new_lines[it].replace(0, 3, "jmp");
        } else {
            continue;
        }


        std::vector<bool> read(new_lines.size(), false);

        int i = 0;
        int acc = 0;
        while (true) {
            if (read[i])
                break;

            std::stringstream line(new_lines[i]);
            read[i] = true;

            std::string inst;
            int value;
            line >> inst >> value;

            if (inst == "nop")
                i++;
            else if (inst == "acc") {
                acc += value;
                i++;
            } else if (inst == "jmp") {
                i += value;
            }

            if (i == (int)new_lines.size()) {
                std::cout << acc << std::endl;
                return;
            }

        }
    }

}