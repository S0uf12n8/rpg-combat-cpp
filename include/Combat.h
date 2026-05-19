#pragma once
#include <vector>
#include"StatusEffect.h"

class Hero;
class Enemy;
class Entity;

class Combat{
private:
    Hero& hero;
    Enemy& enemy;
    std::vector<StatusEffect*>heroEffects;
    std::vector<StatusEffect*>enemyEffects;
    bool heroStunned;
    bool enemyStunned;
    int calculateDamage(Entity& attacker, Entity& defender);
    bool tryDodge(Entity& attacker, Entity& defender);
    void applyEffects(Entity& target, std::vector<StatusEffect*>& effects, bool& stunned);
    void cleanupEffects(std::vector<StatusEffect*>& effects);
public:
    Combat(Hero& hero,Enemy& enemy);
    ~Combat();
    void start();
    bool playerWon() const;
};