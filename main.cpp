#include <iostream>

#include "task1/task1.hpp"
#include "task2/task2.hpp"
#include "task3/task3.hpp"


int main() {
    int n = 3;
    switch (n) {
        case 1:
            task1();
            break;
        case 2:
            task2();
            break;
        case 3:
            task3();
            break;
        default:
            std::cout << "Nu exista taskul " << n << "!\n";
    }

    return 0;
}
