#include <gtest/gtest.h>
#include "../main/BatteryBanks.hpp"

TEST (BatteryBanksTest, InitialState) {
    BatteryBanks batteryBanks;
    ASSERT_EQ(batteryBanks.maxJoltage(), 0);
}

TEST (BatteryBanksTest, AddEmptyBankTest) {
    BatteryBanks batteryBanks;
    batteryBanks.addBank("0000000");
    ASSERT_EQ(batteryBanks.maxJoltage(), 0);
}

TEST (BatteryBanksTest, AddBankWith1Test) {
    BatteryBanks batteryBanks;
    batteryBanks.addBank("0000001");
    ASSERT_EQ(batteryBanks.maxJoltage(), 1);
}

TEST (BatteryBanksTest, AddBankWith10Test) {
    BatteryBanks batteryBanks;
    batteryBanks.addBank("0000010");
    ASSERT_EQ(batteryBanks.maxJoltage(), 10);
}
