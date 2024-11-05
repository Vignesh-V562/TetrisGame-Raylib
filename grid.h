#pragma once
using namespace std;
#include<vector>
#include<raylib.h>

extern const Color darkgrey = {26,31,40,255};
extern const Color green = {47,230,23,255};
extern const Color red = {232,18,18,255};
extern const Color orange = {226,116,17,255};
extern const Color yellow = {237,234,4,255};
extern const Color purple = {166,0,247,255};
extern const Color cyan = {21,204,209,255};
extern const Color blue = {13,64,216,255};  
extern const Color lightBlue = {59,85,162,255};
extern const Color darkBlue = {44,44,127,255};

vector<Color> GetcellColors()
{
  return {darkgrey,green,red,orange,yellow,purple,cyan,blue};   
}


class Grid
{
  private:
     int numRows;
     int numcols;
     int cellSize;
     vector<Color> colors;
     bool ISRowFull(int Row);
     void ClearRow(int Row);
     void MoveRowDown(int Row,int numRows);

  public:
     Grid();
     int grid[20][10];
     void Initialize();
     void Draw();
     bool IsCellOutside(int row,int column);
     bool IsCellEmpty(int row,int column);
     int ClearFullRows();
};

Grid::Grid()
{
    numRows = 20;
    numcols = 10;
    cellSize =30;
    Initialize();
    colors = GetcellColors();
}

void Grid::Initialize()
{
    for(int rows = 0;rows<numRows;rows++)
    {
        for(int columns =0;columns<numcols;columns++)
        {
            grid[rows][columns] = 0;
        }
    }
}

void Grid::Draw()
{
    for(int rows = 0;rows<numRows;rows++)
    {
        for(int columns =0;columns<numcols;columns++)
        {
            int cellValue = grid[rows][columns];
            DrawRectangle(columns*cellSize+ 11 ,rows*cellSize+11 ,cellSize-1 ,cellSize-1 ,colors[cellValue]);
        }
    }    
}

bool Grid::IsCellOutside(int row,int column)
{
    if(row >= 0 && row <numRows && column >=0 && column<numcols)
    {
        return false;
    }
    return true;
}

bool Grid::IsCellEmpty(int row,int column)
{
    if(grid[row][column] == 0)
    {
        return true;
    }
    return false;
}

bool Grid::ISRowFull(int Row)
{
    for(int Column =0;Column<numcols;Column++)
    {
        if(grid[Row][Column]==0)
        {
            return false;
        }
    }
    return true;
}

void Grid::ClearRow(int Row)
{
    if (Row < 0 || Row >= numRows) return;
    for(int Column =0;Column<numcols;Column++)
    {
        grid[Row][Column]= 0;
    }
}

void Grid::MoveRowDown(int Row,int numRows)
{
    if (Row < 0 || Row >= this->numRows || Row + numRows >= this->numRows) return;
    for(int Column =0;Column<numcols;Column++)
    {
        grid[Row + numRows][Column]= grid[Row][Column];
        grid[Row][Column] = 0;
    }
}

int Grid::ClearFullRows()
{
    int completed =0;
    for(int row = numRows - 1; row>=0; row--)
    {
        if(ISRowFull(row)==true)
        {
            ClearRow(row);
            completed++;
        }
        else if(completed>0)
        {
            MoveRowDown(row,completed);
        }
    }
    return completed;
}