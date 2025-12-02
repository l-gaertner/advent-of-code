#include <gtest/gtest.h>
#include "../main/CombinationLock.hpp"


TEST(CombinationLockTest, InitialState) {
    CombinationLock combinationLock;
    ASSERT_EQ(combinationLock.state(), 50);
}

TEST(CombinationLockTest, TurnLeftOnce) {
    CombinationLock combinationLock;
    combinationLock.turn("L1");
    ASSERT_EQ(combinationLock.state(), 49);
}

TEST(CombinationLockTest, TurnRightOnce) {
    CombinationLock combinationLock;
    combinationLock.turn("R1");
    ASSERT_EQ(combinationLock.state(), 51);
}

TEST(CombinationLockTest, TurnLeftAndRight) {
    CombinationLock combinationLock;
    combinationLock.turn("R1");
    combinationLock.turn("L1");
    ASSERT_EQ(combinationLock.state(), 50);
}

TEST(CombinationLockTest, TurnLeftBeyond0) {
    CombinationLock combinationLock;
    combinationLock.turn("L51");
    ASSERT_EQ(combinationLock.state(), 99);
}

TEST(CombinationLockTest, TurnRightBeyond99) {
    CombinationLock combinationLock;
    combinationLock.turn("R50");
    ASSERT_EQ(combinationLock.state(), 0);
}

TEST(CombinationLockTest, Turn1000TimesLeftAndRight) {
    CombinationLock combinationLock;
    combinationLock.turn("R1000");
    combinationLock.turn("L1000");
    ASSERT_EQ(combinationLock.state(), 50);
}

TEST(CombinationLockTest, InitialStateNoPointsAtZero) {
    CombinationLock combinationLock;
    ASSERT_EQ(combinationLock.pointedAtZeroAtEndOfInput(), 0);
}

TEST(CombinationLockTest, TurnLeftOnceNoPointedAtZero) {
    CombinationLock combinationLock;
    combinationLock.turn("L1");
    ASSERT_EQ(combinationLock.pointedAtZeroAtEndOfInput(), 0);
    ASSERT_EQ(combinationLock.pointedAtZero(), 0);
}

TEST(CombinationLockTest, TurnToZero) {
    CombinationLock combinationLock;
    combinationLock.turn("L50");
    ASSERT_EQ(combinationLock.pointedAtZeroAtEndOfInput(), 1);
}

TEST(CombinationLockTest, TurnToZeroTwice) {
    CombinationLock combinationLock;
    combinationLock.turn("L50");
    combinationLock.turn("R100");
    ASSERT_EQ(combinationLock.pointedAtZeroAtEndOfInput(), 2);
}

TEST(CombinationLockTest, TurnOverZeroShouldAddToPointedAtZero) {
    CombinationLock combinationLock;
    combinationLock.turn("L51");
    ASSERT_EQ(combinationLock.pointedAtZero(), 1);
}

TEST(CombinationLockTest, TurnOn100ShouldAddToPointedAtZero) {
    CombinationLock combinationLock;
    combinationLock.turn("R50");
    ASSERT_EQ(combinationLock.pointedAtZero(), 1);
}

TEST(CombinationLockTest, TurnOnZeroShouldAddToPointedAtZero) {
    CombinationLock combinationLock;
    combinationLock.turn("L50");
    ASSERT_EQ(combinationLock.pointedAtZero(), 1);
}

TEST(CombinationLockTest, Turn150LShouldAdd2ToPointedAtZero) {
    CombinationLock combinationLock;
    combinationLock.turn("L150");
    ASSERT_EQ(combinationLock.pointedAtZero(), 2);
}

TEST(CombinationLockTest, Turn50LAnd100RShouldAdd2ToPointedAtZero) {
    CombinationLock combinationLock;
    combinationLock.turn("L50");
    combinationLock.turn("R100");
    ASSERT_EQ(combinationLock.pointedAtZero(), 2);
}

TEST(CombinationLockTest, Turn50LAnd100LShouldAdd2ToPointedAtZero) {
    CombinationLock combinationLock;
    combinationLock.turn("L50");
    combinationLock.turn("L100");
    ASSERT_EQ(combinationLock.pointedAtZero(), 2);
}

TEST(CombinationLockTest, Turn50RAnd100RShouldAdd2ToPointedAtZero) {
    CombinationLock combinationLock;
    combinationLock.turn("R50");
    combinationLock.turn("R100");
    ASSERT_EQ(combinationLock.pointedAtZero(), 2);
}

TEST(CombinationLockTest, TurnOverZero10TimesRightShouldAddToPointedAtZero) {
    CombinationLock combinationLock;
    combinationLock.turn("R1000");
    ASSERT_EQ(combinationLock.pointedAtZero(), 10);
}

TEST(CombinationLockTest, TurnOverZero10TimesLeftShouldAddToPointedAtZero) {
    CombinationLock combinationLock;
    combinationLock.turn("L1000");
    ASSERT_EQ(combinationLock.pointedAtZero(), 10);
}

TEST(CombinationLockTest, TestGiven) {
    CombinationLock combinationLock;
    combinationLock.turn("L68");
    std::cout << combinationLock.pointedAtZero() <<std::endl;
    combinationLock.turn("L30");
    std::cout << combinationLock.pointedAtZero() <<std::endl;
    combinationLock.turn("R48");
    std::cout << combinationLock.pointedAtZero() <<std::endl;
    combinationLock.turn("L5");
    std::cout << combinationLock.pointedAtZero() <<std::endl;
    combinationLock.turn("R60");
    std::cout << combinationLock.pointedAtZero() <<std::endl;
    combinationLock.turn("L55");
    std::cout << combinationLock.pointedAtZero() <<std::endl;
    combinationLock.turn("L1");
    std::cout << combinationLock.pointedAtZero() <<std::endl;
    combinationLock.turn("L99");
    std::cout << combinationLock.pointedAtZero() <<std::endl;
    combinationLock.turn("R14");
    std::cout << combinationLock.pointedAtZero() <<std::endl;
    combinationLock.turn("L82");
    ASSERT_EQ(combinationLock.pointedAtZero(), 6);
}
