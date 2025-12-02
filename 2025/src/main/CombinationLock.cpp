#include "CombinationLock.hpp"

CombinationLock::CombinationLock() {}

int CombinationLock::state() {
    int current_state = starting_state;

    for (std::tuple<char, int> operation : operations) {
        char direction = std::get<0>(operation);
        int amount = std::get<1>(operation);

        //turn
        if (direction == 'L') {
            current_state = current_state - amount;
        } else if (direction == 'R') {
            current_state = current_state + amount;
        } 
    }

    //enforce 0<=current_state<=99
    current_state = current_state % 100;
    if (current_state < 0)
        current_state += 100;

    return current_state;
}

void CombinationLock::turn(std::string value) {
    char direction = value.at(0);
    int amount = std::stoi(value.substr(1, std::string::npos));

    operations.push_back(std::tuple(direction, amount));
}

int CombinationLock::pointedAtZero() {
    int current_state = starting_state;
    int pointed_at_zero = 0;

    for (std::tuple<char, int> operation : operations) {
        char direction = std::get<0>(operation);
        int amount = std::get<1>(operation);

        //turn
        if (direction == 'L') {
            if (current_state == 0) {
                current_state += 100;
            }

            current_state = current_state - amount;

            while (current_state <= 0) {
                current_state += 100;
                pointed_at_zero ++;
            }

            current_state = current_state % 100;

        } else if (direction == 'R') {
            current_state = current_state + amount;
            while (current_state >= 100) {
                current_state -= 100;
                pointed_at_zero ++;
            }
        } 
    }

    return pointed_at_zero;
}

int CombinationLock::pointedAtZeroAtEndOfInput() {
    int current_state = starting_state;
    int pointed_at_zero = 0;

    for (std::tuple<char, int> operation : operations) {
        char direction = std::get<0>(operation);
        int amount = std::get<1>(operation);

        //turn
        if (direction == 'L') {
            current_state = current_state - amount;
        } else if (direction == 'R') {
            current_state = current_state + amount;
        } 

        //enforce 0<=current_state<=99
        current_state = current_state % 100;
        if (current_state < 0)
            current_state += 100;

        if (current_state == 0)
            pointed_at_zero ++;
    }
    return pointed_at_zero;
}
