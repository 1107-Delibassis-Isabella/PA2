#ifndef POSITION_H
#define POSITION_H
#include <iostream>
using namespace std;
#include "linkedlist.h"
#include "arraylist.h"
#include "snakegame.h"

struct Position {
    int row;
    int column;


    //using snakegame local board array
    //SnakeGame* snake = new SnakeGame[];


    bool operator==(const Position& other) const {
        return row == other.row && column == other.column;
    }
    
}; 
#endif