#include "iostream"
#include "raylib.h"
#include "raymath.h"
#include <stack>
#include <vector>
#include "CCell.h"

constexpr int cell_size = 20;
constexpr int rows_colls = 38;
constexpr int window_size = 760;


/**
 * function for getting 2d index into 1d index
 * @param x coord
 * @param y coord
 * @return index of the cell inside the graph
 */
int getIndex(int row, int col)
{
    return row * rows_colls + col;
}




int main() {
    InitWindow(window_size, window_size, "Mazey Mazeey");
    SetTargetFPS(60);


    std::vector<CCell> grid;
    std::stack<int> dfs_stack;







    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(WHITE);


        EndDrawing();
    }
    CloseWindow();
    return 0;
}