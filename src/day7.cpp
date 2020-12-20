#include "day7.h"


bool Day7::contain(std::string parent) {
    for (auto v : contains[parent]) {
        if (v.first == target || contain(v.first))
            return true;
    }
    return false;
}

int Day7::count_bags(std::string parent) {
    int res = 1;
    for (auto v : contains[parent]) {
        res += v.second * count_bags(v.first);
    }
    return res;
}

void Day7::run() {
    // file handling
    std::ifstream file;
    file.open(filename);
    if (!file.is_open()) {
        std::cout << "couldn't open file" << std::endl;
        return;
    }

    // parsing tools
    std::string line;
    std::string v[3];
    int nb;

    while(getline(file, line)){
        std::stringstream ss(line);

        // parent : first bag of the line
        ss >> v[0] >> v[1] >> v[2];
        std::string parent = v[0] + v[1] + v[2];

        // remove finishing 's'
        parent.erase(parent.end() - 1);

        // skip contains
        ss >> v[0];

        while(ss >> nb >> v[0] >> v[1] >> v[2])
        {
            std::string child = v[0] + v[1] + v[2];
            while (child[child.size() - 1] == '.' ||
                   child[child.size() - 1] == ',' ||
                   child[child.size() - 1] == 's')
            {
                child.erase(child.end() - 1);
            }

            contains[parent].push_back(std::make_pair(child, nb));
        }
    }
    file.close();

    // PART 1
    int res = 0;
    for (auto s : contains) {
        if (contain(s.first)) {
            res++;
        }
    }
    // std::cout << res << std::endl;

    // PART 2
    std::cout << count_bags(target) - 1 << std::endl;


}