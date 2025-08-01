#pragma once

/**
 * class to represent single cell inside the maze
 */
class CCell {
public:
    CCell(int x, int y);
    void Draw();


    bool walls[4] = {true, true, true, true}; //top, right, bottom, left
    bool visited = false;
    bool found = false; //found path indicator
private:
    int row, col; //x,y

};
