#pragma once
#include "Enemy.h"
#include <string>

class EnemyFactory {
public:
    static Enemy* createEnemy(const std::string& type);
};
