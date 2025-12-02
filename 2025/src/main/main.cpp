#include <cassert>
#include <fstream>
#include <iostream>

#include "CombinationLock.hpp"

void exerciseOne() {
    CombinationLock combinationLock;
    std::ifstream input("../resources/input-01.txt");
    std::string operation;
    while (input >> operation) {
        combinationLock.turn(operation);
    }
    int value = combinationLock.pointedAtZeroAtEndOfInput();
    assert(value == 1105);
    std::cout << std::format("Exercise 1: combination lock pointing at zero {} times", std::to_string(value)) << std::endl;
}

void exerciseTwo() {
    CombinationLock combinationLock;
    std::ifstream input("../resources/input-01.txt");
    std::string operation;
    while (input >> operation) {
        combinationLock.turn(operation);
    }
    int value = combinationLock.pointedAtZero();
    assert(value == 6599);
    std::cout << std::format("Exercise 1: combination lock pointing at zero {} times\n", value) << std::endl;
}

int main() {
    exerciseOne();
    exerciseTwo();
}
