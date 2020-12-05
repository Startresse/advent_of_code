#include "day5.h"

void Day5::run() {
    std::ifstream file;
    file.open("inputs/input_d5.txt");
    if (!file.is_open()) {
        std::cout << "couldn't open file" << std::endl;
        return;
    }

    std::vector<std::string> strs;
    std::string line;
    while (file >> line) {
        strs.push_back(line);
    }
    file.close();

    for (auto& s : strs) {
        assert(s.size() == 10);
        for (uint i = 0; i < s.size() - 3; ++i) {
            if (s[i] == 'F')
                s[i] = '0';
            else
                s[i] = '1';
        }
        for (uint i = s.size() - 3; i < s.size(); ++i) {
            if (s[i] == 'L')
                s[i] = '0';
            else
                s[i] = '1';
        }
    }

    std::vector<int> rows(strs.size(), 0);
    std::vector<int> cols(strs.size(), 0);
    std::vector<int> seats(strs.size(), 0);
    for (uint i = 0; i < strs.size(); ++i) {
        std::string& s = strs[i];
        int& row = rows[i];
        int& col = cols[i];
        int& seat = seats[i];
        for (uint j = 0; j < s.size() - 3; ++j) {
            row *= 2;
            row += (int)(s[j] - '0');
        }
        for (uint j = s.size() - 3; j < s.size(); ++j) {
            col *= 2;
            col += (int)(s[j] - '0');
        }
        seat = 8 * row + col;
    }

    int max = seats[0];
    int min = seats[0];
    for (int seat : seats) {
        if (seat > max)
            max = seat;
        if (seat < min)
            min = seat;
    }

    const int nb_seats = max - min;
    std::vector<bool> seats_taken(nb_seats, false);
    for (int seat : seats)
        seats_taken[seat - min] = true;

    int empty_seat = -1;
    for (int i = 0; i < nb_seats; ++i) {
        if (!seats_taken[i]) {
            assert(empty_seat = -1);
            empty_seat = i + min;
        }
    }

    std::cout << empty_seat << std::endl;

}