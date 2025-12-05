#include <gtest/gtest.h>
#include "../main/ListOfIngredients.hpp"

TEST (ListOfIngredients, InitialSetupTest) {
    ListOfIngredients listOfIngredients;
    ASSERT_EQ(listOfIngredients.freshIngredients(), 0);
}

TEST (ListOfIngredients, AddFreshIngredientsTest) {
    ListOfIngredients listOfIngredients;
    listOfIngredients.addFreshIngredientRange("1-2\n");
    ASSERT_EQ(listOfIngredients.freshIngredients(), 0);
}

TEST (ListOfIngredients, AddSingleIngredientTest) {
    ListOfIngredients listOfIngredients;
    listOfIngredients.addIngredients("1\n");
    ASSERT_EQ(listOfIngredients.freshIngredients(), 0);
}

TEST (ListOfIngredients, OneFreshIngredientTest) {
    ListOfIngredients listOfIngredients;
    listOfIngredients.addFreshIngredientRange("1-2\n");
    listOfIngredients.addIngredients("1\n");
    ASSERT_EQ(listOfIngredients.freshIngredients(), 1);
}

TEST (ListOfIngredients, OneBadIngredientTest) {
    ListOfIngredients listOfIngredients;
    listOfIngredients.addFreshIngredientRange("1-2\n");
    listOfIngredients.addIngredients("3\n");
    ASSERT_EQ(listOfIngredients.freshIngredients(), 0);
}

TEST (ListOfIngredients, GoodAndBadIngredientsTest) {
    ListOfIngredients listOfIngredients;
    listOfIngredients.addFreshIngredientRange("1-2\n");
    listOfIngredients.addIngredients("1\n3\n");
    ASSERT_EQ(listOfIngredients.freshIngredients(), 1);
}

TEST (ListOfIngredients, MultipleGoodIngredientsTest) {
    ListOfIngredients listOfIngredients;
    listOfIngredients.addFreshIngredientRange("1-2\n");
    listOfIngredients.addIngredients("1\n2\n");
    ASSERT_EQ(listOfIngredients.freshIngredients(), 2);
}

TEST (ListOfIngredients, TestAcceptanceCriteria) {
    ListOfIngredients listOfIngredients;
    listOfIngredients.addFreshIngredientRange("3-5\n");
    listOfIngredients.addFreshIngredientRange("10-14\n");
    listOfIngredients.addFreshIngredientRange("16-20\n");
    listOfIngredients.addFreshIngredientRange("12-18\n");

    std::string ingredients = "1\n"
        "5\n"
        "8\n"
        "11\n"
        "17\n"
        "32\n";
    listOfIngredients.addIngredients(ingredients);

    ASSERT_EQ(listOfIngredients.freshIngredients(), 3);
}
