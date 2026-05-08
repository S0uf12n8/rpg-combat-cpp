#include "Game.h"
#include <iostream>
#include <limits>
#include <cstdlib>
using namespace std;


Game::Game(): running(true){}

void Game::showMainMenu(){
   system("cls");
   system("clear");


   cout << WHITE     // pick a color from Colors.h
         << "  ================================" << "\n"
         << "         Ragnarok                 " << "\n"  // game name here
         << "  ================================" << "\n"
         << RESET << "\n";
    
}
void Game::run(){

}


int Game::getUserChoice(int min, int max){
    int choice;

    while (true)
    {
        cin>>choice;

        if(cin.fail() || choice < min || choice > max){
            cin.clear();
             cin.ignore(                     // throw away bad input
                numeric_limits<streamsize>::max(), '\n'
             
            );
            cout << "  Invalid. Enter "<< min << "-" << max<< ": ";
        }
        else {
            cin.ignore(                     // throw away the leftover \n
                numeric_limits<streamsize>::max(), '\n'
            );
            return choice;                  // valid — return it
        }
    
    }
}

