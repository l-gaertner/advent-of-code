#include "PaperGrid.hpp"
#include <iostream>
#include <string>

char PaperGrid::get_from_grid(int x, int y) {
    if (x < 0 || y < 0 || x >= row_amount || y >= row_length)
        return '.';

    size_t index = x * (row_length + 1) + y;
    return grid[index];
}

bool PaperGrid::is_surrounded_by_lt4(int x, int y) {
    int surrounding_rolls = 0;

    std::tuple<int,int> stencil[8] = {
        {-1,-1},{-1,0},{-1,1},
        {0,-1}, {0,1},
        {1,-1},{1,0},{1,1}
    };

    for (std::tuple<int,int> position : stencil)
        if ( get_from_grid(x + std::get<0>(position), y + std::get<1>(position)) == '@') {
            surrounding_rolls ++;
        }
    return surrounding_rolls < 4;
}

int PaperGrid::removableAmount() {
    if (grid.length() == 0)
        return 0;

    int count = 0;
    for (int a = 0; a <= row_amount; a++)
        for (int b = 0; b <= row_length; b++)
            if (get_from_grid(a, b) == '@')
                if (is_surrounded_by_lt4(a,b))
                    count ++;

    return count;
}

int PaperGrid::removeAllRemoveable() {
    if (grid.length() == 0)
        return 0;

    int count = 0;
    int iteration_count;
    do {
        iteration_count = 0;
        for (int a = 0; a <= row_amount; a++)
            for (int b = 0; b <= row_length; b++)
                if (get_from_grid(a, b) == '@')
                    if (is_surrounded_by_lt4(a,b)) {
                        iteration_count ++;
                        grid[a*(row_length+1) + b] = '.';
                    }
        count += iteration_count;
    } while (iteration_count != 0);

    return count;
}

void PaperGrid::addGrid(std::string value) {
    std::string row;

    row_length = value.find('\n');
    row_amount = 0;
    for (char a : value) 
        if (a == '\n')
            row_amount ++;
    grid = value;
}

