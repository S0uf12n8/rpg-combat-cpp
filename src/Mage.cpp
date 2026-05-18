#include "Mage.h"
#include <iostream>
using namespace std;

Mage::Mage(const std::string& name)
    : Hero(name, Stats(70, 10, 5, 12, 100))
{
}

std::string Mage::getClassName() const {
    return "Mage";
}

void Mage::attack(Entity& target) {
    Hero::attack(target);
}

void Mage::useSkill(Entity& target) {
    if (stats_.getMana() < 25) {
        cout << name_ << " doesn't have enough mana!\n";
        return;
    }
    stats_.spendMana(25);
    target.takeDamage(40);
    cout << name_ << " casts Fireball for 40 damage!\n";
}

void Mage::displayStats() const {
    Hero::displayStats();
}
