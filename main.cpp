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


std::vector<int> GetAllUnvisitedNeighbours(const std::vector<CCell>& grid, int currentIndex)
{
    std::vector<int> res;
    auto& cell = grid[currentIndex];
    const int row = cell.getRow();
    const int col = cell.getCol();

    //top neighbourr
    if(row > 0) {
        int topIndex = getIndex(row - 1, col);
        if(!grid[topIndex].visited) { //check if the cell is visited
            res.emplace_back(topIndex);
        }
    }

    //right neighbour
    if(col < (rows_colls - 1)) {
        int rightIndex = getIndex(row, col + 1);
        if(!grid[rightIndex].visited) {
            res.emplace_back(rightIndex);
        }
    }

    //bottom neighbour
    if(row < (rows_colls - 1)){
        int bottomIndex = getIndex(row + 1, col);
        if(!grid[bottomIndex].visited) {
            res.emplace_back(bottomIndex);
        }
    }

    //left neighbour
    if(col > 0) {
        int leftIndex = getIndex(row, col - 1);
        if(!grid[leftIndex].visited) {
            res.emplace_back(leftIndex);
        }
    }

    return res;
}

int GetRandomNeighbour(const std::vector<int> & neighbours)
{
    int randomIndex = GetRandomValue(0, static_cast<int>(neighbours.size())-1);
    return neighbours[randomIndex];
}

void DeleteWall(CCell& current, CCell& neighbour)
{
    const int currRow = current.getRow();
    const int currCol = current.getCol();

    const int nextRow = neighbour.getRow();
    const int nextCol = neighbour.getCol();

    //next is top neighbour
    if(currRow - 1 == nextRow){
        current.walls[0] = false;
        neighbour.walls[2] = false;
    }
    //next is bot neighbour
    if(currRow  == nextRow - 1){
        current.walls[2] = false;
        neighbour.walls[0] = false;
    }
    //next is right neighbourr
    if(currCol == nextCol - 1){
        current.walls[1] = false;
        neighbour.walls[3] = false;
    }if(currCol - 1 == nextCol){
        current.walls[3] = false;
        neighbour.walls[1] = false;
    }
}

void DFS_Maze(std::vector<CCell>& grid, std::stack<int>& stack, bool& done, int& currentIndex)
{

    if(stack.empty())
    {
        done = true;
        return;
    }
    currentIndex = stack.top();
    CCell& curr = grid[currentIndex];
   /* if(!stack.empty()){
        stack.pop();
    }*/
    curr.visited = true;
    std::vector<int> neighbours = GetAllUnvisitedNeighbours(grid, currentIndex);

    if(!neighbours.empty()) {
        int chosen = GetRandomNeighbour(neighbours);
        CCell& next = grid[chosen];
        DeleteWall(curr, next);
        stack.push(chosen);
    }
    else {
        stack.pop();
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
    int currentIndex = 0; //starting index of generation
    bool mazeCompleted = false;
    dfs_stack.push(currentIndex);
    GraphInit(grid);


    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(WHITE);
        renderMaze(grid);
        //call dfs and showcell

        if(!mazeCompleted)
        {
            DFS_Maze(grid, dfs_stack, mazeCompleted, currentIndex);
            grid[currentIndex].ShowCell();
        }


        EndDrawing();
    }
    CloseWindow();
    return 0;
}