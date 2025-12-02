#ifndef COMBINATION_LOCK_H
#define COMBINATION_LOCK_H

#include <string>
#include <vector>

class CombinationLock {
    private:
        std::vector<std::tuple<char, int>> operations;
        int starting_state = 50;

    public:
        CombinationLock();
        int state();
        void turn(std::string value);
        int pointedAtZero();
        int pointedAtZeroAtEndOfInput();
}; 
#endif
