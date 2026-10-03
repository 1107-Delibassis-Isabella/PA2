#include "snakegame.h"
#incude <iostream> 
using namespace std;

int main() {
    
    SnakeGame game;
    char choice = 'y';

    while (choice == 'y' || choice == 'Y') {
        game = new SnakeGame();

        while (game.getGameOver() == false) {
            char movement;
            game.displayGame();
            cout << "To move the snake, press: " << endl;
            cout << "W for up" << endl;
            cout << "A for left" << endl;
            cout << "S for down" << endl;
            cout << "D for right" << endl;
            cin >> movement;
            while (movement != 'w' && movement != 'W' && movement != 'a' && movement != 'A' && movement != 's' && movement != 'S' && movement != 'd' && movement != 'D') {
                cout << "Invalid move, please try again: " << endl;
                cout << "To move the snake, press: " << endl;
                cout << "W for up" << endl;
                cout << "A for left" << endl;
                cout << "S for down" << endl;
                cout << "D for right" << endl;
                cin >> movement;
            }
            game.directionToMove(movement);
            
        }
    }






    return 0;
}