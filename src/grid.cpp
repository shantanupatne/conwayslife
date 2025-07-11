#include "grid.hpp"
#include "raylib.h"

Grid::Grid(int win_w, int win_h, int cellSize) : cellSize(cellSize),
                                                 rows(win_h / cellSize),
                                                 columns(win_w / cellSize),
                                                 cells(rows, std::vector<int>(columns, 0))
{
}

void Grid::Draw()
{
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < columns; col++)
        {
            Color color = cells[row][col] ? Color{133, 133, 133, 255} : Color{33, 33, 33, 255};
            DrawRectangle(col * cellSize, row * cellSize, cellSize - 1, cellSize - 1, color);
        }
    }
}
void Grid::setCell(int row, int col)
{
    if (checkBounds(row, col))
    {
        cells[row][col] = 1;
    }
}
void Grid::unsetCell(int row, int col)
{
    if (checkBounds(row, col))
    {
        cells[row][col] = 0;
    }
}

bool Grid::checkBounds(int row, int col)
{
    return row >= 0 && row < rows && col >= 0 && col < columns;
}

int Grid::getCellValue(int row, int col)
{
    if (checkBounds(row, col))
        return cells[row][col];
    return 0;
}

void Grid::fillRandom()
{
    for (int row = 0; row < rows; row++)
        for (int col = 0; col < columns; col++)
            cells[row][col] = GetRandomValue(0, 4) == 3 ? 1 : 0;
}
