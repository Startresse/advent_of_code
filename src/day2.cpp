#include "day2.h"

void Day2::run() {
    std::ifstream file;
    file.open("inputs/input_d2.txt");

    std::string verif;
    std::string chara;
    std::string value;

    int count = 0;
    int count_valid = 0;
    while (file >> verif >> chara >> value) {
        std::stringstream ss(verif); 
        int min, max;
        ss >> min >> max;
        max = abs(max);
       
        char c = chara[0];

        int count_chara = 0;
        int i = 0;
        while(value[i]) {
            if (value[i] == c)
                count_chara++;
            ++i;
        }

        if (count_chara <= max && count_chara >= min)
            count++;

        bool first = value[min - 1] == c;
        bool second = value[max - 1] == c;
        if ((first || second) && !(first && second))
        {
            count_valid++;
        }

    }
    std::cout << "res : " << count << std::endl;
    std::cout << "res 2 : " << count_valid << std::endl;

    file.close();
}