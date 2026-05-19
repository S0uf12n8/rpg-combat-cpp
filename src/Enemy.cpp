#include "Enemy.h"
#include <cstdlib>
#include <iostream>

using namespace std;

Enemy::Enemy(const string& name, const Stats& stats, const string& drop, int dropChance, int xp)
    : Entity(name, stats), dropItem(drop), dropChance(dropChance), xpReward(xp) {}

int Enemy::attack(Entity& target) {
    int damage = stats_.getAttack() - target.getStats().getDefense() + (rand() % 5 - 2);
    if (damage < 1) damage = 1;
    target.takeDamage(damage);
    return damage;
}

void Enemy::useSkill(Entity& target) {
}

string Enemy::getType() const {
    return "Enemy";
}

string Enemy::tryDrop() const {
    if (dropItem.empty() || dropChance <= 0) {
        return "";
    }
    int roll = rand() % 100;
    if (roll < dropChance) {
        return dropItem;
    }
    return "";
}

int Enemy::getXPReward() const {
    return xpReward;
}

int Enemy::getDropChance() const {
    return dropChance;
}

string Enemy::getDropItemName() const {
    return dropItem;
}
