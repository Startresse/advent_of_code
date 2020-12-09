#include "day9.h"

int find_invalid_id( std::vector<long> v )
{
    int invalid_id = -1;
    for (int i = 25; i < (int) v.size(); ++i) {

        bool valid = false;
        for (int j = i - 25; j < i; ++j) {
            for (int k = j; k < i; ++k) {
                if (v[j] + v[k] == v[i]) {
                    valid = true;
                    goto endloop;
                }
            }
        }
        endloop:

        if (!valid) {
            invalid_id = i;
            break;
        }

    }
    assert(invalid_id > 0);
    return invalid_id;
}

void Day9::run() {
    std::ifstream file;
    file.open("inputs/input_d9.txt");
    if (!file.is_open()) {
        std::cout << "couldn't open file" << std::endl;
        return;
    }

    std::vector<long> input;
    long value;
    while (file >> value)
        input.push_back(value);
    file.close();

    int i_id = find_invalid_id(input);
    // std::cout << i_id << " : " << input[i_id] << std::endl;

    long invalid = input[i_id];

    int ip = -1;
    int nb = -1;
    for (uint i = 0; i < input.size(); ++i) {
        int sum = input[i];
        int count = 1;
        while (sum < invalid) {
            sum += input[i + count];
            count++;
        }

        if (sum == invalid && count > 1) {
            ip = i;
            nb = count;
            break;
        }
    }

    int max = *std::max_element(input.begin() + ip, input.begin() + ip + nb);
    int min = *std::min_element(input.begin() + ip, input.begin() + ip + nb);
    std::cout << max + min << std::endl;


}