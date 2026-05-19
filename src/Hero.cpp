#include "Hero.h"
#include "Item.h"
#include "Weapon.h"
#include "Armor.h"
#include <iostream>

using namespace std;

Hero::Hero(const string& name, const Stats& stats)
    : Entity(name, stats), level(1), xp(0), xpToNext(100), equippedWeapon(nullptr), equippedArmor(nullptr) {}

int Hero::attack(Entity& target) {
    int rawDamage = stats_.getAttack() + (equippedWeapon ? equippedWeapon->getAttackBonus() : 0);
    int reducedDamage = target.getStats().calculateReducedDamage(rawDamage);
    target.takeDamage(reducedDamage);
    return reducedDamage;
}

void Hero::gainXP(int amount) {
    xp += amount;
    while (xp >= xpToNext) {
        levelUp();
    }
}

void Hero::levelUp() {
    xp -= xpToNext;
    level++;
    xpToNext = level * 100;
}

bool Hero::addItem(Item* item) {
    if (inventory.size() >= 5) {
        return false;
    }
    inventory.push_back(item);
    return true;
}

void Hero::equipWeapon(Weapon* w) {
    if (equippedWeapon) {
        stats_.setAttack(stats_.getAttack() - equippedWeapon->getAttackBonus());
    }
    equippedWeapon = w;
    if (equippedWeapon) {
        stats_.setAttack(stats_.getAttack() + equippedWeapon->getAttackBonus());
    }
}

void Hero::equipArmor(Armor* a) {
    if (equippedArmor) {
        stats_.setDefense(stats_.getDefense() - equippedArmor->getDefenseBonus());
    }
    equippedArmor = a;
    if (equippedArmor) {
        stats_.setDefense(stats_.getDefense() + equippedArmor->getDefenseBonus());
    }
}

int Hero::getLevel() const {
    return level;
}

vector<Item*>& Hero::getInventory() {
    return inventory;
}
