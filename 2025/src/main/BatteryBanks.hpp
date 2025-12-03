#ifndef BATTERY_BANKS_H
#define BATTERY_BANKS_H

#include <string>
#include <vector>
class BatteryBanks {
    private:
        std::vector<std::string> banks;
    public:
        int maxJoltage();
        long maxJoltageWithTwelveBatteries();
        void addBank(std::string bank);
};

#endif
