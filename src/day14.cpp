#include "day14.h"

#define LENGTH 36

enum tril {FALSE, TRUE, NONE = -1};
typedef std::vector<tril> mask;

mask read_mask(std::string line)
{
    mask ret;
    std::stringstream ss(line);
    for (char x; ss >> x;) {
        if (x == 'X')
            ret.push_back(NONE);
        if (x == '0')
            ret.push_back(FALSE);
        if (x == '1')
            ret.push_back(TRUE);
    }
    return ret;
}

void Day14::run() {
    std::ifstream file;
    file.open(filename);
    if (!file.is_open()) {
        std::cout << "couldn't open file" << std::endl;
        return;
    }

    mask mask_m = read_mask("XX0010101XX");
    for (int i = 0; i < mask_m.size(); ++i) {
        std::cout << mask_m[i] << ", ";
    }
    std::cout << "\b\b " << std::endl;

    file.close();
}