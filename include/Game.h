#pragma once
#include <memory>
#include <string>
#include "Hero.h"
#include "Combat.h"
#include "Inventory.h"
#include "ConsoleUI.h"
#include "DataLoader.h"
#include <Colors.h>
class Hero;
class Game {

    private:
        // data members
        bool running;
        std::unique_ptr<Hero> currentHero;
        ConsoleUI ui;
        DataLoader dataLoader;

        
        void showMainMenu();
        void selectHeroClass();
        void gameLoop();
        int getUserChoice(int min, int max);
    
    
        public:
        Game();           
        void run();       


};

