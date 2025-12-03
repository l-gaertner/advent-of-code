#include "BatteryBanks.hpp"

int BatteryBanks::maxJoltage() {
    if (banks.size() > 0) {
        return std::stoi(banks[0]);
    }
    return 0;
}

void BatteryBanks::addBank(std::string bank) {
    banks.push_back(bank);
}
