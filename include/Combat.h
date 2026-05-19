#include "Combat.h"
#include "Hero.h"
#include "Enemy.h"
#include "Entity.h"
#include <iostream>

Combat::Combat(Hero& hero, Enemy& enemy)
    : hero(hero), enemy(enemy), heroStunned(false), enemyStunned(false) {}

Combat::~Combat() {
    cleanupEffects(heroEffects);
    cleanupEffects(enemyEffects);
}