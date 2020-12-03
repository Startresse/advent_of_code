#pragma once

#include <iostream>

class Test {
    private:
        int value;
    public:
        Test();
        Test(int);

        int get_value() { return value; }


};