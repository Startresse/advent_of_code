#include "day2.h"

void Day2::run() {
    std::ifstream file;
    file.open("inputs/input_d2.txt");

    std::string verif;
    std::string chara;
    std::string value;

    int count = 0;
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


    }
    std::cout << "res : " << count << std::endl;

    file.close();
}