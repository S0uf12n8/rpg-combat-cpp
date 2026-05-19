#include "Enemy.h"
#include <cstdlib>
#include <iostream>

using namespace std;

Enemy::Enemy(const string& name, const Stats& stats, const string& drop, int dropChance, int xp)
    : Entity(name, stats), dropItem(drop), dropChance(dropChance), xpReward(xp) {}

int Enemy::attack(Entity& target) {
    int rawDamage = stats_.getAttack();
    int hpBefore = target.getStats().getCurrentHP();
    target.takeDamage(rawDamage);
    return hpBefore - target.getStats().getCurrentHP();
}

void Enemy::useSkill(Entity& target) {
    cout << name_ << " doesn't have a special skill, performing basic attack!\n";
    attack(target);
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
