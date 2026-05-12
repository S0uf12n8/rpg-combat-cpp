#pragma once
#include <memory>
#include <string>

class Hero;

class Game {
public:
    Game();
    ~Game();
    void run();

private:
    bool running;
    std::unique_ptr<Hero> currentHero;

    void showMainMenu();
    void selectHeroClass();
    void gameLoop();
    int getUserChoice(int min, int max);
};