#ifndef LIST_OF_INGREDIENTS_H
#define LIST_OF_INGREDIENTS_H

#include <vector>
#include <string>

class ListOfIngredients {
    private:
        std::string ingredients;
        std::vector<std::tuple<long,long>> fresh_ingredient_ranges;
        std::vector<bool> fresh_ingredient_ids;
        void create_fresh_ingredient_ids_vector();
        bool is_ingredient_fresh(long ingredient);
    public:
        int freshIngredients();
        void addFreshIngredientRange(std::string range);
        void addIngredients(std::string val);
};

#endif
