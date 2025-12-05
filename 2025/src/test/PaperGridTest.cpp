#include <gtest/gtest.h>
#include "../main/PaperGrid.hpp"

TEST (PaperGridTest, TestInitialState) {
    PaperGrid paper_grid;
    ASSERT_EQ(paper_grid.removableAmount(), 0);
}

TEST (PaperGridTest, Add1x1Grid) {
    PaperGrid paper_grid;
    paper_grid.addGrid(".\n");
    ASSERT_EQ(paper_grid.removableAmount(), 0);
}

TEST (PaperGridTest, Add1x1GridWithPaperRoll) {
    PaperGrid paper_grid;
    paper_grid.addGrid("@\n");
    ASSERT_EQ(paper_grid.removableAmount(), 1);
}

TEST (PaperGridTest, Add2x2GridWithPaperRoll) {
    PaperGrid paper_grid;
    paper_grid.addGrid("..\n@.\n");
    ASSERT_EQ(paper_grid.removableAmount(), 1);
}

TEST (PaperGridTest, Add3x3GridWithPaperRoll) {
    PaperGrid paper_grid;
    std::string grid = 
        "@..\n"
        "...\n"
        "...\n";
    paper_grid.addGrid(grid);
    ASSERT_EQ(paper_grid.removableAmount(), 1);
}

TEST (PaperGridTest, Add3x3GridWithoutAnyPaperRoll) {
    PaperGrid paper_grid;
    std::string grid = 
        "...\n"
        "...\n"
        "...\n";
    paper_grid.addGrid(grid);
    ASSERT_EQ(paper_grid.removableAmount(), 0);
}

TEST (PaperGridTest, Add3x3GridWith4PaperRolls) {
    PaperGrid paper_grid;
    std::string grid = 
        "@.@\n"
        "...\n"
        "@.@\n";
    paper_grid.addGrid(grid);
    ASSERT_EQ(paper_grid.removableAmount(), 4);
}

TEST (PaperGridTest, Add3x3GridWith4RemovablePaperRolls) {
    PaperGrid paper_grid;
    std::string grid = 
        "@.@\n"
        ".@.\n"
        "@.@\n";
    paper_grid.addGrid(grid);
    ASSERT_EQ(paper_grid.removableAmount(), 4);
}

TEST (PaperGridTest, Add3x3GridFullOfPaperRolls) {
    PaperGrid paper_grid;
    std::string grid = 
        "@@@\n"
        "@@@\n"
        "@@@\n";
    paper_grid.addGrid(grid);
    ASSERT_EQ(paper_grid.removableAmount(), 4);
}

TEST (PaperGridTest, TestGiven) {
    PaperGrid paper_grid;
    std::string grid = 
        "..@@.@@@@.\n"
        "@@@.@.@.@@\n"
        "@@@@@.@.@@\n"
        "@.@@@@..@.\n"
        "@@.@@@@.@@\n"
        ".@@@@@@@.@\n"
        ".@.@.@.@@@\n"
        "@.@@@.@@@@\n"
        ".@@@@@@@@.\n"
        "@.@.@@@.@.\n";
    paper_grid.addGrid(grid);
    ASSERT_EQ(paper_grid.removableAmount(), 13);
}

TEST (PaperGridTest, TestRemoveAllRemoveableAdd3x3GridFullOfPaperRolls) {
    PaperGrid paper_grid;
    std::string grid = 
        "@@@\n"
        "@@@\n"
        "@@@\n";
    paper_grid.addGrid(grid);
    ASSERT_EQ(paper_grid.removeAllRemoveable(), 9);
}

TEST (PaperGridTest, TestGiven_02) {
    PaperGrid paper_grid;
    std::string grid = 
        "..@@.@@@@.\n"
        "@@@.@.@.@@\n"
        "@@@@@.@.@@\n"
        "@.@@@@..@.\n"
        "@@.@@@@.@@\n"
        ".@@@@@@@.@\n"
        ".@.@.@.@@@\n"
        "@.@@@.@@@@\n"
        ".@@@@@@@@.\n"
        "@.@.@@@.@.\n";
    paper_grid.addGrid(grid);
    ASSERT_EQ(paper_grid.removeAllRemoveable(), 43);
}
