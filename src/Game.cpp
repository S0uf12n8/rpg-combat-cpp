#include "Game.h"
#include "Hero.h"
#include "Colors.h"
#include <iostream>
#include <limits>
#include <cstdlib>
using namespace std;

Game::Game() : running(true) {}
Game::~Game() = default;

void Game::showMainMenu() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif

    cout << WHITE
         << "  ================================\n"
         << "           Ragnarok               \n"
         << "  ================================\n"
         << RESET << "\n";

    cout << BOLD << "  [1]" << RESET << " New Game\n";
    cout << BOLD << "  [2]" << RESET << " Load Game\n";
    cout << BOLD << "  [3]" << RESET << " Exit\n";
    cout << "\n > ";
}

void Game::run() {
    while (running) {
        showMainMenu();
        int choice = getUserChoice(1, 3);

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

void Game::selectHeroClass() {
    cout << CYAN << "\n  [Hero selection coming soon]\n" << RESET;
}

void Game::gameLoop() {
    cout << CYAN << "\n  [Game loop coming soon]\n" << RESET;
}

int Game::getUserChoice(int min, int max) {
    int choice;
    while (true) {
        cin >> choice;
        if (cin.fail() || choice < min || choice > max) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "  Invalid. Enter " << min << "-" << max << ": ";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return choice;
        }
    }
}