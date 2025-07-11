#pragma once
#include "grid.hpp"


class Simulation
{
private:
    Grid grid, temp_grid;
    bool isRunning {false};

public:
    Simulation(int width, int height, int cellsize) : grid(width, height, cellsize), temp_grid(width, height, cellsize) {grid.fillRandom();};
    void Draw() { grid.Draw(); };
    void setCell(int row, int col) { grid.setCell(row, col); };
    int countLiveNeighbours(int row, int col);
    void tick();
    void Run() {isRunning = !isRunning;} // start = True, stop =  false
};
