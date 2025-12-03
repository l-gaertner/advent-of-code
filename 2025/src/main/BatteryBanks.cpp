#include "BatteryBanks.hpp"
#include <iostream>
#include <string>

long helper(int num_batteries, std::vector<std::string> banks) {
    long sum = 0;
    for (std::string current_bank : banks) {

        std::string max_value = "";
        char max_value_of_bank = '0';
        int position_of_max_value = -1;

        for (int j = 1; j <= num_batteries; j++) {
            position_of_max_value ++;
            int start_interval =  position_of_max_value;
            int end_interval = current_bank.length() - (num_batteries - j);

            for (int a = start_interval; a < end_interval; a++) {
                if (int(max_value_of_bank) < current_bank[a]) {
                    max_value_of_bank = current_bank[a];
                    position_of_max_value = a;
                }
            }

            max_value.push_back(max_value_of_bank);
            max_value_of_bank = '0';
        }

        sum += std::stol(max_value);
    }
    return sum;
}

int BatteryBanks::maxJoltage() {
    return helper(2, banks);
}

long BatteryBanks::maxJoltageWithTwelveBatteries() {
    return helper(12, banks);
}

void BatteryBanks::addBank(std::string bank) {
    banks.push_back(bank);
}
