#include "iostream"
#include "raylib.h"
#include "raymath.h"
#include <stack>
#include <vector>
#include "CCell.h"

constexpr int rows_colls = 40;
constexpr int window_size = 800;


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

/**
 * fill the graph with cells
 * @param grid graph
 */
void GraphInit(std::vector<CCell>& grid)
{
    for (int i = 0; i < rows_colls; ++i) {
        for (int j = 0; j < rows_colls ; ++j) {
            grid.emplace_back(CCell(i,j));
        }
    }
}

void renderMaze(std::vector<CCell>& grid)
{
    for (auto& cell : grid) {
        cell.Draw();
    }
}

int main() {
    InitWindow(window_size, window_size, "Mazey Mazeey");
    SetTargetFPS(60);


    std::vector<CCell> grid; //graph
    std::stack<int> dfs_stack; //stack of indexes
    GraphInit(grid);


    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(WHITE);
        renderMaze(grid);





        EndDrawing();
    }
    CloseWindow();
    return 0;
}