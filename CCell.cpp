
#include "CCell.h"


constexpr int cell_size = 20;

CCell::CCell(int r, int c) : row(r), col(c){}

void CCell::Draw() const{
    int x = getCoordinateX();
    int y = getCoordinateY();

    if(visited)
    {
        DrawRectangle(x,y, cell_size, cell_size, RED);
    }


    if(walls[0]) { //top
        DrawLine(x,y, x + cell_size, y, BLACK);
    }if(walls[1]) { //right
        DrawLine(x + cell_size,y, x + cell_size, y + cell_size, BLACK);
    } if(walls[2]) { // bottom
        DrawLine(x ,y + cell_size, x + cell_size, y + cell_size, BLACK);
    } if(walls[3]) { //left
        DrawLine(x,y + cell_size, x , y, BLACK);
    }



}

void CCell::ShowCell() const{

    //value in pixels
    int x = getCoordinateX();
    int y = getCoordinateY();
    DrawRectangle(x, y, cell_size-2, cell_size-2, YELLOW);
}

int CCell::getCoordinateX() const {
    return col * cell_size;
}

int CCell::getCoordinateY() const {
    return row * cell_size;
}

