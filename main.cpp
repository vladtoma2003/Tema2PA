#include <iostream>

#include "task1/problema1.hpp"
#include "task2/problema2.hpp"
#include "task3/problema3.hpp"


int main(int argc, char* argv[]) {
//    int n;
    switch (std::stoi(argv[1])) {
        case 1:
            problema1();
            break;
        case 2:
            problema2();
            break;
        case 3:
            problema3();
            break;
        default:
            std::cout << "Nu exista taskul " << argv[1] << "!\n";
    }

    return 0;
}
