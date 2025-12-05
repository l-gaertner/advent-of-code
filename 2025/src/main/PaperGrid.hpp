#ifndef PAPER_GRID_H
#define PAPER_GRID_H

#include <string>
#include <vector>
class PaperGrid {
    private:
        std::string grid;
        int buffer_size = 0;
        int row_length = 0;
        int row_amount = 0;
        char get_from_grid(int x, int y);
        bool is_surrounded_by_lt4(int x, int y);
    public:
        int removableAmount();
        int removeAllRemoveable();
        void addGrid(std::string value);
};

#endif
