#include "Archer.h"
#include <iostream>

using namespace std;

Archer::Archer(const string& name)
    : Hero(name, Stats(90, 14, 8, 11, 40)) {}

string Archer::getType() const {
    return "Archer";
}

void Archer::useSkill(Entity& target) {
    if (stats_.getMana() < 15) {
        cout << "Not enough mana!\n";
        return;
    }

    cout << name_ << " uses Precise Shot!\n";
    stats_.spendMana(15);

    // Deal stats_.getAttack() damage, completely ignoring target's defense
    target.takeDamage(stats_.getAttack() + target.getStats().getDefense());
}

void Archer::levelUp() {
    Hero::levelUp();
    stats_.setMaxHP(stats_.getMaxHP() + 20);
    stats_.heal(20);
    stats_.setAttack(stats_.getAttack() + 3);
    stats_.setDefense(stats_.getDefense() + 2);
    stats_.setSpeed(stats_.getSpeed() + 3);
    stats_.setMaxMana(stats_.getMaxMana() + 5);
    stats_.restoreMana(5);
    cout << name_ << " leveled up! Quick and deadly!\n";
}
