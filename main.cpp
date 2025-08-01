#include "iostream"
#include "raylib.h"
#include "raymath.h"
#include <stack>
#include <vector>
#include "CCell.h"

constexpr int cell_size = 20;
constexpr int rows_colls = 38;
constexpr int window_size = 760;

int main() {
    InitWindow(window_size, window_size, "Mazey Mazeey");
    SetTargetFPS(60);








    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(WHITE);


        EndDrawing();
    }
    CloseWindow();
    return 0;
}