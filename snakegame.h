#ifndef SNAKEGAME_H
#define SNAKEGAME_H
#include <cstdlib>
#include <iostream>
#include "arraylist.h"
#include "linkedlist.h"
#include "position.h"

class SnakeGame {
    int row;
    int column;
 

    using SnakeBody = ArrayList<Position>;

    SnakeBody snakeSegment;
    Position food;

    SnakeGame();
    //char movement; might declare movement in main.cpp
    int currentScore = 0;
    int currentLength = 3;
    bool endGame = false;
    
    void displayGame();
    void displayGameOver();
    void directionToMove(char);
    bool restartOrExit(char);
    void appearFood();


    bool getGameOver();
    bool findPositionOfSnake(Position);
    void reset();


};
#endif