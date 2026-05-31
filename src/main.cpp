#include "Game.h"
#include <ctime>
#include <cstdlib>

int main(){
    srand(static_cast<unsigned int>(time(nullptr)));
    #ifdef _WIN32
        system("chcp 65001 > nul");
    #endif
    Game game;
    game.run();
    return 0;
}