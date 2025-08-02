
#include "CCell.h"


constexpr int cell_size = 20;

CCell::CCell(int r, int c) : row(r), col(c){}

void CCell::Draw() const{
    int x = getCoordinateX();
    int y = getCoordinateY();

    if(visited)
    {
        DrawRectangle(x,y, cell_size, cell_size, DARKGREEN);
    }


    if(walls[0]) { //top
        //DrawLine(x,y, x + cell_size, y, BLACK);
        DrawLineEx({(float)x, (float)y}, {(float)(x + cell_size), (float)y}, 3.0f, WHITE);

    }if(walls[1]) { //right
        //DrawLine(x + cell_size,y, x + cell_size, y + cell_size, BLACK);
        DrawLineEx({(float)x + cell_size, (float)y}, {(float)(x + cell_size), (float)y + cell_size}, 3.0f, WHITE);

    } if(walls[2]) { // bottom
        // DrawLine(x ,y + cell_size, x + cell_size, y + cell_size, BLACK);
        DrawLineEx({(float)x, (float)y + cell_size}, {(float)(x + cell_size), (float)y +cell_size}, 3.0f, WHITE);
    } if(walls[3]) { //left
        DrawLineEx({(float)x, (float)y + cell_size}, {(float)(x ), (float)y}, 3.0f, WHITE);
        //DrawLine(x,y + cell_size, x , y, BLACK);
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

