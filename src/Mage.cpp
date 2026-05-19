#include "Mage.h"
#include <iostream>

using namespace std;

Mage::Mage(const string& name)
    : Hero(name, Stats(70, 10, 5, 12, 100)) {}

string Mage::getType() const {
    return "Mage";
}

void Mage::useSkill(Entity& target) {
    if (stats_.getMana() < 25) {
        cout << "Not enough mana!\n";
        return;
    }

    cout << name_ << " casts Fireball!\n";
    stats_.spendMana(25);

    // Deal exactly 40 damage, completely ignoring defense
    target.takeDamage(40 + target.getStats().getDefense());
}

void Mage::levelUp() {
    Hero::levelUp();
    stats_.setMaxHP(stats_.getMaxHP() + 15);
    stats_.heal(15);
    stats_.setAttack(stats_.getAttack() + 2);
    stats_.setDefense(stats_.getDefense() + 1);
    stats_.setSpeed(stats_.getSpeed() + 2);
    stats_.setMaxMana(stats_.getMaxMana() + 15);
    stats_.restoreMana(15);
    cout << name_ << " leveled up! Arcane power flows through you!\n";
}
