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
