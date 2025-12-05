#include <cassert>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "BatteryBanks.hpp"
#include "CombinationLock.hpp"
#include "ListOfIngredients.hpp"
#include "PaperGrid.hpp"
#include "ProductIdRanges.hpp"

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
    std::cout << std::format("Exercise 1: combination lock pointing at zero {} times", value) << std::endl;
}

void exerciseThree() {
    ProductIdRanges productIdRanges;
    std::ifstream input("../resources/input-02.txt");
    std::string ranges;
    while (input >> ranges) {
        productIdRanges.addMultipleProductIdRanges(ranges);
    }
    long long value = productIdRanges.invalidIdSum();
    std::cout << std::format("Exercise 3: sum of invalid ids {}", value) << std::endl;
    assert(value == 23039913998);
}

void exerciseFour() {
    ProductIdRanges productIdRanges;
    std::ifstream input("../resources/input-02.txt");
    std::string ranges;
    while (input >> ranges) {
        productIdRanges.addMultipleProductIdRanges(ranges);
    }
    long long value = productIdRanges.invalidIdSum_ex2();
    std::cout << std::format("Exercise 4: sum of invalid ids {}", value) << std::endl;
    assert(value == 35950619148);
}

void exerciseFive() {
    BatteryBanks batteryBanks;
    std::ifstream input("../resources/input-03.txt");
    std::string bank;
    while (input >> bank) {
        batteryBanks.addBank(bank);
    }
    long long value = batteryBanks.maxJoltage();
    std::cout << std::format("Exercise 5: max joltage of battery banks {}", value) << std::endl;
    assert(value == 16973);
}

void exerciseSix() {
    BatteryBanks batteryBanks;
    std::ifstream input("../resources/input-03.txt");
    std::string bank;
    while (input >> bank) {
        batteryBanks.addBank(bank);
    }
    long long value = batteryBanks.maxJoltageWithTwelveBatteries();
    std::cout << std::format("Exercise 6: max joltage of battery banks with twelve batteries {}", value) << std::endl;
    assert(value == 168027167146027);
}

void exerciseSeven() {
    PaperGrid paperGrid;
    std::ifstream input("../resources/input-04.txt");
    std::stringstream buffer;
    buffer << input.rdbuf();

    paperGrid.addGrid(buffer.str());
    long long value = paperGrid.removableAmount();
    std::cout << std::format("Exercise 7: amount of removeable paper rolls {}", value) << std::endl;
    assert(value == 1451);
}

void exerciseEight() {
    PaperGrid paperGrid;
    std::ifstream input("../resources/input-04.txt");
    std::stringstream buffer;
    buffer << input.rdbuf();

    paperGrid.addGrid(buffer.str());
    long long value = paperGrid.removeAllRemoveable();
    std::cout << std::format("Exercise 8: amount of iteratively removeable paper rolls {}", value) << std::endl;
    // assert(value == 1451);
}

void exerciseNine() {
    ListOfIngredients listOfIngredients;
    std::ifstream input("../resources/input-05.txt");
    std::stringstream buffer;
    buffer << input.rdbuf();
    std::string string_input = buffer.str();

    size_t delimiter = string_input.find("\n\n");

    std::stringstream ingredient_ranges_stream(string_input.substr(0, delimiter));
    std::string ingredient_range;
    while (ingredient_ranges_stream >> ingredient_range) {
        listOfIngredients.addFreshIngredientRange(ingredient_range);
    }

    listOfIngredients.addIngredients(string_input.substr(delimiter + 1, std::string::npos));

    int value = listOfIngredients.freshIngredients();
    std::cout << std::format("Exercise 9: amount of fresh ingredients {}", value) << std::endl;
    // assert(value == 1451);
}

int main() {
    exerciseOne();
    exerciseTwo();
    exerciseThree();
    exerciseFour();
    exerciseFive();
    exerciseSix();
    exerciseSeven();
    exerciseEight();
    exerciseNine();
}
