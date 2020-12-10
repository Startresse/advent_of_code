#include "day10.h"

long long Day10::dp(int i)
{
    if (i == (int) values.size() - 1)
        return 1;

    if (dp_map.find(i) != dp_map.end()) {
        return dp_map.at(i);
    }

    long long res = 0;
    uint j = i + 1;
    while (values[j] - values[i] <= 3 && j < values.size()) {
        res += dp(j);
        ++j;
    }

    dp_map.insert(std::make_pair(i, res));
    return res;
    
}

void Day10::run() {
    std::ifstream file;
    file.open(filename);
    if (!file.is_open()) {
        std::cout << "couldn't open file" << std::endl;
        return;
    }

    values.clear();
    int value;
    while(file >> value)
        values.push_back(value);
    file.close();

    values.push_back(0);
    std::sort(values.begin(), values.end());
    values.push_back(values[values.size() - 1] + 3);

    int n1 = 0;
    int n3 = 0;
    for (uint i = 0; i < values.size() - 1; ++i) {
        int d = values[i + 1] - values[i];
        if (d == 1)
            n1++;

        if (d == 3)
            n3++;
    }
    std::cout << n3 * n1 << std::endl;
    std::cout << dp(0) << std::endl;
    
}