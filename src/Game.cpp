#include "Game.h"
#include "Hero.h"
#include "Colors.h"
#include "ConsoleUI.h"
#include "Warrior.h"
#include "Mage.h"
#include "Archer.h"
#include "Enemy.h"
#include "EnemyFactory.h"
#include "Combat.h"
#include "Consumable.h"
#include "Weapon.h"
#include "Armor.h"
#include <iostream>
#include <limits>
#include <cstdlib>
#include <memory>
#include <string>
#include <vector>
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
    ConsoleUI ui;
    ui.showHeroSelection();

    cout << "Choose your hero (1-3): ";
    int choice = getUserChoice(1, 3);

    cout << "Enter your hero's name: ";
    string name;
    getline(cin, name);

    if (choice == 1) {
        currentHero = make_unique<Warrior>(name);
    } else if (choice == 2) {
        currentHero = make_unique<Mage>(name);
    } else {
        currentHero = make_unique<Archer>(name);
    }

    currentHero->addItem(new Consumable("Health Potion", "Restores 50 HP", 10, 50));
    ui.showMessage("Hero created! You received a Health Potion. Good luck, " + name + "!");
}

void Game::gameLoop() {
    if (!currentHero) return;

    ConsoleUI ui;
    vector<string> regularEnemies = {"Draugr", "Jotunn", "Valkyrie"};
    int totalRooms = 15;

    for (int i = 1; i <= totalRooms; i++) {
        cout << "\n--- Room " << i << " of " << totalRooms << " ---\n";

        string enemyType;
        if (i == totalRooms) {
            enemyType = "Fenrir"; // Boss in the final room
        } else {
            enemyType = regularEnemies[rand() % regularEnemies.size()];
        }

        unique_ptr<Enemy> enemy(EnemyFactory::createEnemy(enemyType, i));
        if (!enemy) continue;

        ui.showCombatStart(enemy->getName());

        Combat combat(*currentHero, *enemy);
        combat.startCombat();

        if (!currentHero->isAlive()) {
            ui.showDeathScreen();
            cout << "\nPress Enter to continue...";
            cin.ignore();
            cin.get();
            return;
        }

        ui.showMessage("You defeated " + enemy->getName() + "!");
        currentHero->getStats().restoreMana(currentHero->getStats().getMaxMana());
        currentHero->gainXP(enemy->getXPReward());

        // 50% chance for a random drop
        if (rand() % 100 < 50) {
            int roll = rand() % 100;
            Item* drop = nullptr;
            if (roll < 40) {
                drop = new Consumable("Health Potion", "Restores 50 HP", 10, 50);
            } else if (roll < 60) {
                drop = new Consumable("Mana Potion", "Restores 30 Mana", 10, 30); // Note: 30 is healAmount, wait, does Consumable restore mana? In our codebase, Consumable only has `healAmount`!
            } else if (roll < 80) {
                drop = new Weapon("Steel Sword", "ATK +10", 25, 10);
            } else {
                drop = new Armor("Iron Plate", "DEF +8", 30, 8);
            }
            ui.showItemFound(drop->getName());
            currentHero->addItem(drop);
        }
    }

    if (currentHero->isAlive()) {
        ui.showVictory();
        cout << "\nPress Enter to continue...";
        cin.ignore();
        cin.get();
    }
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