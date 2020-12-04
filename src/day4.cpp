#include "day4.h"

bool Passport::is_north_pole() {
    return
        byr != -1 &&
        iyr != -1 &&
        eyr != -1 &&
        hgt != "" &&
        hcl != "" &&
        ecl != "" &&
        pid != "";
}

bool Passport::is_complete() {
    return is_north_pole() && cid != -1;
}

void Passport::add_field(std::string s) {
    std::string field = s.substr(0, 3);

    size_t end = s.size() - 1;
    if (field == "byr")
        byr = atoi(s.substr(4, end).c_str());
    else if (field == "iyr")
        iyr = atoi(s.substr(4, end).c_str());
    else if (field == "eyr")
        eyr = atoi(s.substr(4, end).c_str());
    else if (field == "hgt")
        hgt = s.substr(4, end);
    else if (field == "hcl")
        hcl = s.substr(4, end);
    else if (field == "ecl")
        ecl = s.substr(4, end);
    else if (field == "pid")
        pid = s.substr(4, end);
    else if (field == "cid")
        cid = atoi(s.substr(4, end).c_str());
    else {
        std::cout << field << " : ";
        std::cout << "invalid type" << std::endl;

    }


}

const std::vector<std::string> ecl_types = {"amb", "blu", "brn", "gry", "grn", "hzl", "oth"};
const std::regex hcl_check("#[a-f0-9]{6}");
const std::regex pid_check("[0-9]{9}");
bool Passport::is_valid() {
    if (!is_north_pole())
        return false;

    if (byr < 1920 || byr > 2002)
        return false;

    if (iyr < 2010 || iyr > 2020)
        return false;
    
    if (eyr < 2020 || eyr > 2030)
        return false;

    size_t sz = hgt.size();
    std::string hgt_tp = hgt.substr(sz - 2, sz - 1);
    int hgt_i = atoi(hgt.substr(0, sz - 2).c_str());
    if (hgt_tp == "cm") {
        if (hgt_i < 150 || hgt_i > 193)
            return false;
    } else if (hgt_tp == "in") {
        if (hgt_i < 59 || hgt_i > 76)
            return false;
    } 
    else
        return false;

    if(!std::regex_match(hcl, hcl_check))
        return false;
    
    bool found = false;
    for (auto s : ecl_types) {
        if (ecl == s)
            found = true;
    }
    if (!found)
        return false;

    if(!std::regex_match(pid, pid_check))
        return false;

    return true;
}

void Day4::run() {

    std::ifstream file;
    file.open("inputs/input_d4.txt");
    if (!file.is_open()) {
        std::cout << "couldn't open file" << std::endl;
        return;
    }

    int count = 0;
    std::string line;
    while (getline(file, line)) {
        Passport p;
        
        while(line != "") {
            std::stringstream ss(line);

            std::string field;
            while(ss >> field) {
                p.add_field(field);
            }

            getline(file, line);
        }

        if (p.is_valid())
            count++;
    }

    std::cout << count << std::endl;

    file.close();
}