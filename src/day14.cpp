#include "day14.h"

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

integer int2bin(int val) {
    integer ret(LENGTH, false);
    for (int i = LENGTH - 1; i >= 0; --i) {
        ret[i] = val % 2;
        val /= 2;
    }
    return ret;
}

long bin2int(integer val) {
    long ret = 0;
    for (int i = 0; i < LENGTH; ++i) {
        ret *= 2;
        ret += val[i];
    }
    return ret;
}

integer apply_mask(integer val, mask m) {
    for (int i = 0; i < LENGTH; ++i) {
        if (m[i] == TRUE)
            val[i] = true;
        if (m[i] == FALSE)
            val[i] = false;
    }
    return val;
}

void Day14::run() {
    std::ifstream file;
    file.open(filename);
    if (!file.is_open()) {
        std::cout << "couldn't open file" << std::endl;
        return;
    }

    std::map<int, integer> memory;

    std::string line;
    std::string w;
    mask m;
    while (getline(file, line)) {
        std::stringstream ss(line);
        ss >> w;
        if (w == "mask") {
            ss >> w;
            ss >> w;
            m = read_mask(w);
        } else {
            std::stringstream sss(w);

            // get mem_pos;
            char c;
            for (int i = 0; i < 4; ++i) {sss >> c;}
            int mem_pos;
            sss >> mem_pos;

            // get value
            std::string x;
            ss >> x;
            int value;
            ss >> value;

            // calculate and change memory
            integer val = int2bin(value);
            integer calc = apply_mask(val, m);
            if (memory.find(mem_pos) == memory.end())
                memory.emplace(mem_pos, calc);
            else
                memory[mem_pos] = calc;
            
        }
    }

    long long res = 0;
    for (auto v : memory) {
        std::cout << bin2int(v.second) << std::endl;
        res += bin2int(v.second);
    }
    std::cout << "result : " << res << std::endl;


    file.close();
}