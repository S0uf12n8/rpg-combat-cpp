#include "EnemyFactory.h"

Enemy* EnemyFactory::createEnemy(const std::string& type) {
    if (type == "Draugr") {
        return new Enemy("Draugr", Stats(40, 8, 3, 6, 0), "Health Potion", 40, 30);
    } else if (type == "Jotunn") {
        return new Enemy("Jotunn", Stats(70, 14, 6, 5, 0), "Iron Sword", 20, 50);
    } else if (type == "Valkyrie") {
        return new Enemy("Valkyrie", Stats(55, 12, 8, 15, 0), "Mana Potion", 30, 45);
    } else if (type == "Fenrir") {
        return new Enemy("Fenrir", Stats(150, 22, 10, 13, 0), "none", 0, 200);
    } else {
        return nullptr;
    }
}
