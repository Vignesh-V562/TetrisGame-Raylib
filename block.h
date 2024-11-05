#pragma once
using namespace std;
#include<vector>
#include<map>
#include"position.h"
#include"grid.h"

class Block
{
   public:
      Block();
      int Id;
      map<int,vector<position>> cells;
      void Draw(int OffsetX,int OffsetY);
      void Move(int row,int column);
      vector<position>GetCellPositions();
      void Rotate();
      void UndoRotation();

    private:
      int cellSize;
      int rotationState;
      vector<Color> colors;
      int rowOffset; 
      int colOffset;
};

Block::Block()
{
    cellSize = 30;
    rotationState =0;
    colors = GetcellColors();
    rowOffset =0;
    colOffset =0;
}

void Block::Draw(int OffsetX,int OffsetY)
{
    vector<position> tiles = GetCellPositions();
    for(position item:tiles)
    {
        DrawRectangle(item.column*cellSize + OffsetX  ,item.row*cellSize + OffsetY ,cellSize-1 ,cellSize-1 ,colors[Id]);
    }
}

void Block::Move(int row,int column)
{
     rowOffset += row;
     colOffset +=column;
}

vector<position> Block::GetCellPositions()
{
  vector<position> tiles = cells[rotationState];
  vector<position> MovedTiles;
  for(position item:tiles)
  {
    position newPos = {item.row+rowOffset,item.column+colOffset};
    MovedTiles.push_back(newPos);
  }
  return MovedTiles;
}

void Block::Rotate()
{
    rotationState++;
    if(rotationState == (int)cells.size())
    {
      rotationState =0;
    }
}

void Block::UndoRotation()
{
  rotationState--;
  if(rotationState == -1)
  {
    rotationState = cells.size() -1;
  }
}

class LBlock: public Block
{
   public:
   LBlock()
   {
     Id =1;
     cells[0] = {position(0,2),position(1,0),position(1,1),position(1,2)};
     cells[1] = {position(0,1),position(1,1),position(2,1),position(2,2)};
     cells[2] = {position(1,0),position(1,1),position(1,2),position(2,0)};
     cells[3] = {position(0,0),position(0,1),position(1,1),position(2,1)};
     Move(0,3);
   }
};

class JBlock: public Block
{
   public:
   JBlock()
   {
     Id =2;
     cells[0] = {position(0,0),position(1,0),position(1,1),position(1,2)};
     cells[1] = {position(0,1),position(0,2),position(1,1),position(2,1)};
     cells[2] = {position(1,0),position(1,1),position(1,2),position(2,2)};
     cells[3] = {position(0,1),position(1,1),position(2,0),position(2,1)};
     Move(0,3);
   }
};

class IBlock: public Block
{
   public:
   IBlock()
   {
     Id =3;
     cells[0] = {position(1,3),position(1,0),position(1,1),position(1,2)};
     cells[1] = {position(1,2),position(0,2),position(2,2),position(3,2)};
     cells[2] = {position(2,0),position(2,1),position(2,2),position(2,3)};
     cells[3] = {position(0,1),position(1,1),position(3,1),position(2,1)};
     Move(-1,3);
   }
};

class OBlock: public Block
{
   public:
   OBlock()
   {
     Id =4;
     cells[0] = {position(0,0),position(0,1),position(1,0),position(1,1)};
     Move(0,4);
   }
};

class SBlock: public Block
{
   public:
   SBlock()
   {
     Id =5;
     cells[0] = {position(0,1),position(0,2),position(1,0),position(1,1)};
     cells[1] = {position(1,1),position(0,1),position(1,2),position(2,2)};
     cells[2] = {position(1,1),position(2,1),position(1,2),position(2,0)};
     cells[3] = {position(0,0),position(1,1),position(1,0),position(2,1)};
     Move(0,3);
   }
};

class TBlock: public Block
{
   public:
   TBlock()
   {
     Id =6;
     cells[0] = {position(1,2),position(0,1),position(1,0),position(1,1)};
     cells[1] = {position(2,1),position(0,1),position(1,2),position(1,1)};
     cells[2] = {position(1,2),position(2,1),position(1,0),position(1,1)};
     cells[3] = {position(2,1),position(0,1),position(1,0),position(1,1)};
     Move(0,3);
   }
};

class ZBlock: public Block
{
   public:
   ZBlock()
   {
     Id =7;
     cells[0] = {position(0,0),position(0,1),position(1,2),position(1,1)};
     cells[1] = {position(0,2),position(2,1),position(1,2),position(1,1)};
     cells[2] = {position(2,2),position(2,1),position(1,0),position(1,1)};
     cells[3] = {position(2,0),position(0,1),position(1,0),position(1,1)};
     Move(0,3);
   }
};