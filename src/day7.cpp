#include "day7.h"

void Day7::run() {
    std::ifstream file;
    file.open(filename);
    if (!file.is_open()) {
        std::cout << "couldn't open file" << std::endl;
        return;
    }

    std::vector<std::string> lines;
    std::string line;
    while(getline(file, line)){
        lines.push_back(line);
    }
    file.close();

    std::string target = "shinygoldbag";

    for(auto s : lines) {
        std::stringstream ss(s);

        std::string v[3];
        ss >> v[0] >> v[1] >> v[2];
        std::string container = v[0] + v[1] + v[2];
        container.erase(container.end() - 1);

        // skip contains
        ss >> v[0];

        // std::cout << container << std::endl;
        int nb;
        while(ss >> nb >> v[0] >> v[1] >> v[2])
        {
            std::string bag = v[0] + v[1] + v[2];
            while (bag[bag.size() - 1] == '.' || bag[bag.size() - 1] == ',' || bag[bag.size() - 1] == 's')
                bag.erase(bag.end() - 1);

            // std::cout << "> " << nb << " : " << bag << std::endl;

            std::vector<std::string>& parent_list = parents[bag];
            if (std::find(parent_list.begin(), parent_list.end(), container) != parent_list.end())
                parent_list.push_back(container);

            std::vector<std::pair<std::string, int>>& child_list = childs[container];
            child_list.push_back(std::make_pair(bag, nb));
        }

    }

    for (auto p : parents)
    {
        std::cout << p.first << std::endl << "> ";
        for (auto s : p.second) {
            std::cout << s << ", ";
        }
        std::cout << std::endl;
    }

}