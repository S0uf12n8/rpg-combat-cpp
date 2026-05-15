#pragma once

class Hero;
class Entity;

class Combat{
public:
    Combat(Hero& hero,Entity& enemy);

    void startCombat();
    void heroTurn();
    void enemyTurn();
    void applyEffects();
    bool isCombatOver();

private:
    Hero& hero;
    Entity& enemy;
    int maxRounds;
};