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

TEST (BatteryBanksTest, AddBankWith101Test) {
    BatteryBanks batteryBanks;
    batteryBanks.addBank("00000101");
    ASSERT_EQ(batteryBanks.maxJoltage(), 11);
}

TEST (BatteryBanksTest, AddBankWith898Test) {
    BatteryBanks batteryBanks;
    batteryBanks.addBank("00089801");
    ASSERT_EQ(batteryBanks.maxJoltage(), 98);
}

TEST (BatteryBanksTest, TestOneGivenBank) {
    BatteryBanks batteryBanks;
    batteryBanks.addBank("811111111111119");
    ASSERT_EQ(batteryBanks.maxJoltage(), 89);
}

TEST (BatteryBanksTest, TestMultipleBanks) {
    BatteryBanks batteryBanks;
    batteryBanks.addBank("000001");
    batteryBanks.addBank("00001");
    ASSERT_EQ(batteryBanks.maxJoltage(), 2);
}

TEST (BatteryBanksTest, TestAllGivenBanks) {
    BatteryBanks batteryBanks;
    batteryBanks.addBank("987654321111111");
    batteryBanks.addBank("811111111111119");
    batteryBanks.addBank("234234234234278");
    batteryBanks.addBank("818181911112111");
    ASSERT_EQ(batteryBanks.maxJoltage(), 357);
}

TEST (BatteryBanksTest, TestOneBankWithTwelveBatteries0) {
    BatteryBanks batteryBanks;
    batteryBanks.addBank("000000000000000");
    ASSERT_EQ(batteryBanks.maxJoltageWithTwelveBatteries(), 0);
}

TEST (BatteryBanksTest, TestOneGivenBankWithTwelveBatteries) {
    BatteryBanks batteryBanks;
    batteryBanks.addBank("987654321111111");
    ASSERT_EQ(batteryBanks.maxJoltageWithTwelveBatteries(), 987654321111);
}


TEST (BatteryBanksTest, TestSecondGivenBankWithTwelveBatteries) {
    BatteryBanks batteryBanks;
    batteryBanks.addBank("811111111111119");
    ASSERT_EQ(batteryBanks.maxJoltageWithTwelveBatteries(), 811111111119);
}

TEST (BatteryBanksTest, TestThirdGivenBankWithTwelveBatteries) {
    BatteryBanks batteryBanks;
    batteryBanks.addBank("234234234234278");
    ASSERT_EQ(batteryBanks.maxJoltageWithTwelveBatteries(), 434234234278);
}

TEST (BatteryBanksTest, TestFourthGivenBankWithTwelveBatteries) {
    BatteryBanks batteryBanks;
    batteryBanks.addBank("818181911112111");
    ASSERT_EQ(batteryBanks.maxJoltageWithTwelveBatteries(), 888911112111);
}
