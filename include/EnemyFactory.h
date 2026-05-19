#pragma once
#include "Enemy.h"

class EnemyFactory {
public:
    static Enemy createRandom(); // randomly returns Draugr, Jotunn, or Valkyrie
    static Enemy createBoss();   // always returns Fenrir
};
