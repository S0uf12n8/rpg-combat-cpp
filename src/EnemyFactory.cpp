#include "EnemyFactory.h"
#include <cstdlib>

Enemy EnemyFactory::createRandom() {
    int choice = std::rand() % 3;
    if (choice == 0) {
        return Enemy("Draugr", Stats(40, 8, 3, 6, 0), "Health Potion", 40, 30);
    } else if (choice == 1) {
        return Enemy("Jotunn", Stats(70, 14, 6, 5, 0), "Iron Sword", 20, 50);
    } else {
        return Enemy("Valkyrie", Stats(55, 12, 8, 15, 0), "Mana Potion", 30, 45);
    }
}

Enemy EnemyFactory::createBoss() {
    return Enemy("Fenrir", Stats(150, 22, 10, 13, 0), "", 0, 200);
}
