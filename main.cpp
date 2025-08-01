#include "iostream"
#include "raylib.h"
#include "raymath.h"
#include <stack>
#include <vector>
#include "CCell.h"

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


    std::vector<CCell> grid; //graph
    std::stack<int> dfs_stack; //stack of indexes


    for (int i = 0; i < rows_colls; ++i) {
        for (int j = 0; j < rows_colls ; ++j) {
            grid.emplace_back(CCell(i,j));
        }
    }



    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(WHITE);

        /*for (auto& cell : grid) {
            cell.visited = true;
        }
        for (const auto& cell : grid) {
            cell.Draw();
        }*/
        EndDrawing();
    }
    CloseWindow();
    return 0;
}