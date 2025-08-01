#pragma once

#include "raylib.h"
/**
 * class to represent single cell inside the maze
 */
class CCell {
public:
    CCell(int r, int c);
    void Draw() const;
    void ShowCell() const;


    bool walls[4] = {true, true, true, true}; //top, right, bottom, left
    bool visited = false;
    bool found = false; //found path indicator
private:
    [[nodiscard]] int getCoordinateX() const;
    [[nodiscard]] int getCoordinateY() const;

    int row, col; //x,y

};
