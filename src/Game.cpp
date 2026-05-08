#include "Game.h"
#include <iostream>
#include <limits>
#include <cstdlib>
using namespace std;


Game::Game(): running(true){}

void Game::showMainMenu(){
   #ifdef _WIN32 
        system("cls");
   #esle 
        system("clear");
   #endif

   cout << WHITE     // pick a color from Colors.h
         << "  ================================" << "\n"
         << "         Ragnarok                 " << "\n"  // game name here
         << "  ================================" << "\n"
         << RESET << "\n";
    cout << BOLD << "  [1]" << RESET << " New Game" << "\n";  
    cout << BOLD << "  [2]" << RESET << " Load Game" << "\n";  
    cout << BOLD << "  [3]" << RESET << " Exit" << "\n";  

    cout << "\n > ";
}




void Game::run(){
     while (running) {          // what keeps the loop going?
        
        showMainMenu();               // show the menu first
        
        int choice = getUserChoice(1, 3);   // get player input between 1 and 3

        switch (choice) {
            case 1:
                selectHeroClass();
                gameLoop();
                break;
            case 2:
                cout << CYAN << "\n  Coming soon...\n" << RESET;
                break;
            case 3:
                cout << YELLOW << "\n  Skål! Until next time.\n" << RESET;
                running = false;   
                break;
        }
    }
}


int Game::getUserChoice(int min, int max){
    int choice;

    while (true)
    {
        cin>>choice;

        if(cin.fail() || choice < min || choice > max){
            cin.clear();
             cin.ignore(                     
                numeric_limits<streamsize>::max(), '\n'
             
            );
            cout << "  Invalid. Enter "<< min << "-" << max<< ": ";
        }
        else {
            cin.ignore(                     
                numeric_limits<streamsize>::max(), '\n'
            );
            return choice;                  
        }
    
    }
}

void Game::selectHeroClass() {
    
    cout << CYAN << "\n  [Hero selection coming soon]\n" << RESET;
}

void Game::gameLoop() {
    
    cout << CYAN << "\n  [Game loop coming soon]\n" << RESET;
}