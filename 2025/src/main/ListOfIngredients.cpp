#include "ListOfIngredients.hpp"
#include <iostream>
#include <sstream>

int ListOfIngredients::freshIngredients() {

    create_fresh_ingredient_ids_vector();

    int counter = 0;
    std::string ingredient;
    std::stringstream ingredient_stream(ingredients);
    while (ingredient_stream >> ingredient)
        if (is_ingredient_fresh(std::stol(ingredient)))
            counter++;

    return counter;
}

void ListOfIngredients::addFreshIngredientRange(std::string range) {
    int delimiter_index = range.find('-');
    long range_start = std::stol(range.substr(0, delimiter_index));
    long range_end = std::stol(range.substr(delimiter_index + 1, std::string::npos));

    fresh_ingredient_ranges.push_back({range_start, range_end});
}

void ListOfIngredients::addIngredients(std::string val) {
    ingredients = val;
}

bool ListOfIngredients::is_ingredient_fresh(long ingredient) {
    for (std::tuple<long,long> range : fresh_ingredient_ranges) {
        long ingredient_int = ingredient;
        if (ingredient_int >= std::get<0>(range) && ingredient_int <= std::get<1>(range))
            return true;
    }
    return false;
}

void ListOfIngredients::create_fresh_ingredient_ids_vector() {
}
