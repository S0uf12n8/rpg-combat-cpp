#include "Game.h"


int main(){
    #ifdef _WIN32
        system("chcp 65001 > nul");  
    #endif
    Game game;
    game.run();
    return 0;
}