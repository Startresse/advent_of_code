#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <regex>

class Day4 {
    private:

    public:
        Day4() {}

        void run();
};

class Passport {
public:
    int byr = -1;
    int iyr = -1;
    int eyr = -1;
    std::string hgt = "";
    std::string hcl = "";
    std::string ecl = "";
    std::string pid = "";
    int cid = -1;

    bool is_north_pole();
    bool is_complete();

    bool is_valid();

    void add_field(std::string);
    friend std::ostream& operator<<(std::ostream& os, const Passport& p);
};

std::ostream& operator<<(std::ostream& os, const Passport& p) {
    os << "byr:" << p.byr << std::endl;
    os << "iyr:" << p.iyr << std::endl;
    os << "eyr:" << p.eyr << std::endl;
    os << "hgt:" << p.hgt << std::endl;
    os << "hcl:" << p.hcl << std::endl;
    os << "ecl:" << p.ecl << std::endl;
    os << "pid:" << p.pid << std::endl;
    os << "cid:" << p.cid << std::endl;
    return os;
}