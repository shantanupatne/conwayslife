#pragma once
#include <vector>

class Grid
{
public:
    Grid(int win_w, int win_h, int cellSize);
    void Draw();
    void setCell(int row, int col);
    void unsetCell(int row, int col);
    bool checkBounds(int row, int col);
    int getCellValue(int row, int col);
    int getRows() { return rows; };
    int getColumns() { return columns; };
    void fillRandom();

private:
    int cellSize{}, rows{}, columns{};
    std::vector<std::vector<int>> cells;
};