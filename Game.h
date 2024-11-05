#pragma once
using namespace std;
#include"grid.h"
#include"block.h"
#include<random>

class Game
{
  private:
    vector<Block> blocks;
    Block CurrentBlock;
    Block NextBlock;
    void RotateBlock();
    void LockBlock();
    bool BlockFits();
    void Reset();
    void UpdateScore(int linesCleared,int movedownpoint);
    Grid grid;
    Block GetRandomBlock();
    vector<Block> GetAllBlocks();
    void MoveBlockLeft();
    void MoveBlockRight();
    bool IsBlockoutside();

  public:
    Game();
    void Draw();
    void HandleInput();
    void MoveBlockDown();
    bool GameOver;
    int Score;
};

Game::Game()
{
    grid =Grid();
    blocks = GetAllBlocks();
    CurrentBlock= GetRandomBlock();
    NextBlock = GetRandomBlock();
    GameOver = false;
    Score=0;
}

Block Game::GetRandomBlock()
{
    if(blocks.empty())
    {
        blocks = GetAllBlocks();
    }
    int RandomIndex = rand()% blocks.size();
    Block blo = blocks[RandomIndex];
    blocks.erase(blocks.begin() + RandomIndex);
    return blo;
}

vector<Block> Game::GetAllBlocks()
{
    return {LBlock(),JBlock(),IBlock(),OBlock(),SBlock(),TBlock(),ZBlock()};
}

void Game::Draw()
{
    grid.Draw();
    CurrentBlock.Draw(11,11);
    switch(NextBlock.Id)
    {
      case 3:
        NextBlock.Draw(255,290);
        break;
      case 4:
        NextBlock.Draw(255,280);
        break;
      default:
        NextBlock.Draw(270,270);
        break;
    }
}

void Game::MoveBlockLeft()
{
    if(!GameOver)
    {
      CurrentBlock.Move(0,-1);
      if(IsBlockoutside() || BlockFits()==false)
      {
        CurrentBlock.Move(0,1);
      }
    }
}

void Game::MoveBlockRight()
{
    if(!GameOver)
    {
      CurrentBlock.Move(0,1);
      if(IsBlockoutside() || BlockFits()==false)
      {
        CurrentBlock.Move(0,-1);
      }
    }
}

void Game::MoveBlockDown()
{
    if(!GameOver)
    {
       CurrentBlock.Move(1,0);
       if(IsBlockoutside() || BlockFits() == false)
       {
         CurrentBlock.Move(-1,0);
         LockBlock();
       }
    }
}

void Game::HandleInput()
{
    int Key = GetKeyPressed();
    if(GameOver && Key !=0)
    {
        GameOver = false;
        Reset();
    }
    switch(Key)
    {
      case KEY_LEFT:
        MoveBlockLeft();
        break;
      case KEY_RIGHT:
        MoveBlockRight();
        break;
      case KEY_DOWN:
        MoveBlockDown();
        UpdateScore(0,1);
        break;
      case KEY_UP:
        RotateBlock();
        break;
      default:
        break;
    }
}

bool Game::IsBlockoutside()
{   vector<position> tiles = CurrentBlock.GetCellPositions();
    for(position item:tiles)
    {
        bool status = grid.IsCellOutside(item.row,item.column);
        if(status == true)
        {
            return true;
        }
    }
    return false;
}

void Game::RotateBlock()
{
    if(!GameOver)
    {
      CurrentBlock.Rotate();
      if(IsBlockoutside())
      {
        CurrentBlock.UndoRotation();
      }
    }
}

void Game::LockBlock()
{
    vector<position> tiles = CurrentBlock.GetCellPositions();
    for(position item: tiles)
    {
        grid.grid[item.row][item.column] = CurrentBlock.Id;
    }
    CurrentBlock = NextBlock;
    if(BlockFits() == false)
    {
        GameOver = true;
    }
    NextBlock = GetRandomBlock();
    int rowsCleared = grid.ClearFullRows();
    UpdateScore(rowsCleared,0);
}

bool Game::BlockFits()
{
    vector<position> tiles = CurrentBlock.GetCellPositions();
    for(position item: tiles)
    {
        if(grid.IsCellEmpty(item.row,item.column) == false)
        {
           return false;
        }
    }
    return true;
}

void Game::Reset()
{
    grid.Initialize();
    blocks = GetAllBlocks();
    CurrentBlock = GetRandomBlock();
    NextBlock = GetRandomBlock();
    Score = 0;
}

void Game::UpdateScore(int linesCleared,int movedownpoint)
{
    switch(linesCleared)
    {
      case 1:
        Score += 100;
        break;
      case 2:
        Score += 200;
        break;
      case 3:
        Score += 500;
        break;
      default:
        break;
    }
    Score += movedownpoint;
}