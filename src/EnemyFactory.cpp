#include "EnemyFactory.h"

Enemy* EnemyFactory::createEnemy(const std::string& type, int level) {
    double scale = 1.0 + (level * 0.2);
    if (type == "Draugr") {
        return new Enemy("Draugr", Stats(40 * scale, 8 * scale, 3 * scale, 6 * scale, 0), "Health Potion", 40, 30 * scale);
    } else if (type == "Jotunn") {
        return new Enemy("Jotunn", Stats(70 * scale, 14 * scale, 6 * scale, 5 * scale, 0), "Iron Sword", 20, 50 * scale);
    } else if (type == "Valkyrie") {
        return new Enemy("Valkyrie", Stats(55 * scale, 12 * scale, 8 * scale, 15 * scale, 0), "Mana Potion", 30, 45 * scale);
    } else if (type == "Fenrir") {
        return new Enemy("Fenrir", Stats(150 * scale, 22 * scale, 10 * scale, 13 * scale, 0), "none", 0, 200 * scale);
    } else {
        return nullptr;
    }
}
