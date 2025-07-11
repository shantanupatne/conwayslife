#include <iostream>
#include "raylib.h"

#include "simulation.hpp"

Color GREY = {11, 11, 11, 255};

int main() {
    const int win_w{1000}, win_h{1000}, cellSize{10}, maxFPS{60}, minFPS{5};
    int FPS {30};
    InitWindow(win_w, win_h, "Conway's Game of Life");
    SetTargetFPS(FPS);
    
    Simulation game{win_w, win_h, cellSize};
    
    // game.setCell(5, 29);
    // game.setCell(6, 0);
    // game.setCell(5, 0);
    // game.setCell(4, 0);
    // std::cout << game.countLiveNeighbours(5, 29) << std::endl;
    while (!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(GREY);
        if (IsKeyPressed(KEY_SPACE)) game.Run();
        if (IsKeyPressed(KEY_C)) game.clearGrid();
        if (IsKeyPressed(KEY_R)) game.createRandomState();
        
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && !game.IsSimRunning()) {
            Vector2 mousePos = GetMousePosition();
            int row = mousePos.y / cellSize;
            int col = mousePos.x / cellSize;
            game.setCell(row, col);
        }
        if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT) && !game.IsSimRunning()) {
            Vector2 mousePos = GetMousePosition();
            int row = mousePos.y / cellSize;
            int col = mousePos.x / cellSize;
            game.unsetCell(row, col);
        }

        if (IsKeyPressed(KEY_F) && FPS < maxFPS) {
            FPS += 5;
            SetTargetFPS(FPS);
        }
        if (IsKeyPressed(KEY_S) && FPS > minFPS) {
            FPS -= 5;
            SetTargetFPS(FPS);
        }
        game.tick();
        game.Draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
