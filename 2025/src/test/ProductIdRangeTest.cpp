#include <gtest/gtest.h>
#include "../main/ProductIdRanges.hpp"

TEST(ProductIdRangeTest, InitialState) {
    ProductIdRanges productIdRanges;
    ASSERT_EQ(productIdRanges.invalidIdSum(), 0);
}

TEST(ProductIdRangeTest, AddProductIdRangeWithoutInvalidIds) {
    ProductIdRanges productIdRanges;
    productIdRanges.addProductIdRange("12-13");
    ASSERT_EQ(productIdRanges.invalidIdSum(), 0);
}

TEST(ProductIdRangeTest, AddProductIdRangeWithInvalidId11) {
    ProductIdRanges productIdRanges;
    productIdRanges.addProductIdRange("11-12");
    ASSERT_EQ(productIdRanges.invalidIdSum(), 11);
}

TEST(ProductIdRangeTest, AddProductIdRangeWithInvalidId22) {
    ProductIdRanges productIdRanges;
    productIdRanges.addProductIdRange("22-23");
    ASSERT_EQ(productIdRanges.invalidIdSum(), 22);
}

TEST(ProductIdRangeTest, AddProductIdRangeWithInvalidId22AtEnd) {
    ProductIdRanges productIdRanges;
    productIdRanges.addProductIdRange("21-22");
    ASSERT_EQ(productIdRanges.invalidIdSum(), 22);
}

TEST(ProductIdRangeTest, AddProductIdRangeWithInvalidId22InTheRange) {
    ProductIdRanges productIdRanges;
    productIdRanges.addProductIdRange("21-23");
    ASSERT_EQ(productIdRanges.invalidIdSum(), 22);
}

TEST(ProductIdRangeTest, AddProductIdRangeWithInvalidId22And33InTheRange) {
    ProductIdRanges productIdRanges;
    productIdRanges.addProductIdRange("21-33");
    ASSERT_EQ(productIdRanges.invalidIdSum(), 55);
}

TEST(ProductIdRangeTest, AddProductIdRangeWithInvalidId1010InTheRange) {
    ProductIdRanges productIdRanges;
    productIdRanges.addProductIdRange("998-1012");
    ASSERT_EQ(productIdRanges.invalidIdSum(), 1010);
}

TEST(ProductIdRangeTest, AddProductIdRangeWithInvalidId2222InTheRange) {
    ProductIdRanges productIdRanges;
    productIdRanges.addProductIdRange("2222-2224");
    ASSERT_EQ(productIdRanges.invalidIdSum(), 2222);
}

TEST(ProductIdRangeTest, AddProductIdRangeWithValidId2233InTheRange) {
    ProductIdRanges productIdRanges;
    productIdRanges.addProductIdRange("2233-2234");
    ASSERT_EQ(productIdRanges.invalidIdSum(), 0);
}

TEST(ProductIdRangeTest, AddProductIdRangeWithInvalidId2323InTheRange) {
    ProductIdRanges productIdRanges;
    productIdRanges.addProductIdRange("2323-2324");
    ASSERT_EQ(productIdRanges.invalidIdSum(), 2323);
}

TEST(ProductIdRangeTest, AddProductIdRangeWithInvalidIds2323And2424InTheRange) {
    ProductIdRanges productIdRanges;
    productIdRanges.addProductIdRange("2323-2425");
    ASSERT_EQ(productIdRanges.invalidIdSum(), 4747);
}

TEST(ProductIdRangeTest, AddProductIdRangeWithInvalidId101InTheRange) {
    ProductIdRanges productIdRanges;
    productIdRanges.addProductIdRange("101-102");
    ASSERT_EQ(productIdRanges.invalidIdSum(), 0);
}

TEST(ProductIdRangesTest, AddMultipleProductIdRangesWithValidId101InTheRange) {
    ProductIdRanges productIdRanges;
    productIdRanges.addMultipleProductIdRanges("101-102");
    ASSERT_EQ(productIdRanges.invalidIdSum(), 0);
}

TEST(ProductIdRangesTest, AddMultipleProductIdRangesWithInvalidId1010InTheRange) {
    ProductIdRanges productIdRanges;
    productIdRanges.addMultipleProductIdRanges("998-1012,1202-1203");
    ASSERT_EQ(productIdRanges.invalidIdSum(), 1010);
}

TEST(ProductIdRangesTest, TestGiven) {
    ProductIdRanges productIdRanges;
    productIdRanges.addMultipleProductIdRanges("11-22,95-115,998-1012,1188511880-1188511890,222220-222224,1698522-1698528,446443-446449,38593856-38593862,565653-565659,824824821-824824827,2121212118-2121212124");
    ASSERT_EQ(productIdRanges.invalidIdSum(), 1227775554);
}

TEST(ProductIdRangesTest, TextEx2999) {
    ProductIdRanges productIdRanges;
    productIdRanges.addMultipleProductIdRanges("11-12");
    ASSERT_EQ(productIdRanges.invalidIdSum_ex2(), 11);
}

TEST(ProductIdRangesTest, TestGiven_ex2) {
    ProductIdRanges productIdRanges;
    productIdRanges.addMultipleProductIdRanges("11-22,95-115,998-1012,1188511880-1188511890,222220-222224,1698522-1698528,446443-446449,38593856-38593862,565653-565659,824824821-824824827,2121212118-2121212124");
    ASSERT_EQ(productIdRanges.invalidIdSum_ex2(), 4174379265);
}
