#pragma once
#include "grid.hpp"


class Simulation
{
private:
    Grid grid, temp_grid;
    bool isRunning {false};

public:
    Simulation(int width, int height, int cellsize) : grid(width, height, cellsize), temp_grid(width, height, cellsize) {};
    void Draw() { grid.Draw(); };
    void setCell(int row, int col) { grid.setCell(row, col); };
    void unsetCell(int row, int col) { grid.unsetCell(row, col); };
    int countLiveNeighbours(int row, int col);
    void tick();
    bool IsSimRunning() {return isRunning; };
    void Run() {isRunning = !isRunning;} // start = True, stop =  false
    void clearGrid();
    void createRandomState();
};
