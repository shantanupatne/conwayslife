#include "simulation.hpp"
#include <utility>
#include <vector>

int Simulation::countLiveNeighbours(int row, int col)
{
    int liveNeighbours{};

    std::vector<std::pair<int, int>> neighbourOffsets {
        {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}
    };

    for (const auto& offset : neighbourOffsets) {
        int neighRow = (row + offset.first + grid.getRows()) % grid.getRows();
        int neighCol = (col + offset.second + grid.getColumns()) % grid.getColumns();
        liveNeighbours += grid.getCellValue(neighRow, neighCol);
    }
    return liveNeighbours;
}

void Simulation::tick() {
    if (isRunning) {
        for (int row = 0; row < grid.getRows(); ++row) {
            for (int col = 0; col < grid.getColumns(); ++col) {
                int liveNei = countLiveNeighbours(row, col);
                int cellVal = grid.getCellValue(row, col);
    
                if (cellVal > 0) {
                    // Cell survives if it has 2 or 3 live neighbors
                    (liveNei < 2 || liveNei > 3) ? temp_grid.unsetCell(row, col) : temp_grid.setCell(row, col);
                } else {
                    // Dead cell becomes alive if it has exactly 3 live neighbors
                    (liveNei == 3) ? temp_grid.setCell(row, col) : temp_grid.unsetCell(row, col);
                }
            }
        }
    
        grid = temp_grid;
    }
}