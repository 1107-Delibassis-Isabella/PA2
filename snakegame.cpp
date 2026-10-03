#include "snakegame.h"

SnakeGame::SnakeGame() {
    reset();
}


void SnakeGame::displayGame() {
    for (int i = 0; i < row; i++) {
        if (i == 0 || i == (row-1)) {
            cout << "####################" << endl;
        }
        for (int j = 0; j < column; j++) {
                
            Position temp{i, j};
            if (j == 0) {
                cout << "#";
            } else if (j == column -1) {
                cout << "#" << endl;
            } else if (findPositionOfSnake(temp) == true ){
                if (snakeSegment.getLength() > 0 && snakeSegment[0] == temp) {
                    cout << "O" << endl;
                } else {
                    cout << "o" << endl;
                }
            } else if (food == temp) {
                cout << "*" << endl;
            } else {
                cout << " " << endl;
            }
        }
    }
    cout << "Current Score: " << currentScore << endl;
    cout << "Current Length: " << currentLength << endl;
}

void SnakeGame::directionToMove(char input) {
    Position current{snakeSegment[0]};
    Position n = current;
    
    if (input == 'w' || input == 'W') {
        n.row--;
        if (n.row == 0) {
            cout << "You hit a wall! You lose!" << endl;
            displayGameOver();
        }
    } else if (input == 'a' || input == 'A') {
        n.column--;
        if (n.column == 0) {
            cout << "You hit a wall! You lose!" << endl;
            displayGameOver();
        }
    } else if (input == 's' || input == 'S') {
        n.row++;
        if (n.row >= row) {
            cout << "You hit a wall! You lose!" << endl;
            displayGameOver();
        }

    } else if (input == 'd' || input == 'D') {
        n.column++;
        if (n.column >= column) {
            cout << "You hit a wall! You lose!" << endl;
            displayGameOver();
        }
    } else if (input == 'q' || input == 'Q') {
        restartOrExit('q'); 
        return; 
    }

    if (n == food) {
        currentLength++;
        appearFood();
    }
}

void SnakeGame::displayGameOver() {
    char answer;
    endGame = true;
    cout << "GAME OVER! You lost! Would you like to restart or quit?" << endl;
    cout << "Your final score was: " << currentScore << endl;
    cout << "R for restart or Q for quit: ";
    cin >> answer; 
    while (answer != 'r' && answer != 'R' && answer != 'q' && answer != 'Q') {
        cout << "Invalid response, please try again: " << endl;
        cin >> answer;
    }
    restartOrExit(answer);
}

bool SnakeGame::restartOrExit(char choice) {
    if (choice == 'q' || choice == 'Q') {
        //Should quit the game entirely
        return false;
    } else if (choice == 'r' || choice == 'R') {
        return true;
    }
}

bool SnakeGame::getGameOver() {
    return endGame;
}

void SnakeGame::appearFood() {
    bool foodPosition = false;
    int foodRow, foodColumn;
    if (snakeSegment.getLength() >= (row - 2) * (column - 2)) {
        return;
    } else {
        while (foodPosition = false) {
            foodRow = (rand() % (row - 2)) + 1;
            foodColumn = (rand() % (column - 2)) + 1;
            Position temp{foodRow, foodColumn};
            if (findPositionOfSnake(temp) == false) {
                food = temp;
                break;
            }
        }
    }
}

bool SnakeGame::findPositionOfSnake(Position p) {
    for (int i = 0; i < snakeSegment.getLength(); i++) {
        if (snakeSegment[i] == p) {
            return true;
        }
    }
    return false; 
}

void SnakeGame::reset() {
    currentScore = 0;
    currentLength = 3; 
}