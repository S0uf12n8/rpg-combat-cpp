#pragma once
#include "ConsoleUI.h"

class Hero;
class Entity;

class Combat {
private:
    Hero&     hero;
    Entity&   enemy;
    int       maxRounds;
    bool      escaped_;
    ConsoleUI ui;

    int  calculateDamage(Entity& attacker, Entity& defender);
    bool tryDodge(Entity& attacker, Entity& defender);

public:
    Combat(Hero& hero, Entity& enemy);

    void startCombat();
    void heroTurn();
    void enemyTurn();
    void applyEffects();
    bool isCombatOver();
};
