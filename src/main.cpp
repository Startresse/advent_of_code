#include <iostream>

#include "test.h"

int main(void) {
    Test t(100);
    std::cout << t.get_value() << std::endl;
}