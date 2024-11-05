#pragma once

class position
{
    public:
        position(int row,int column);
        int row ;
        int column;
};

position::position(int row,int column)
{
    this->row = row;
    this->column = column;
}