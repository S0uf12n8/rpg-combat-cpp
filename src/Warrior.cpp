#include "Warrior.h"
#include <iostream>
using namespace std;

Warrior::Warrior(const std::string& name)
    : Hero(name, Stats(120, 18, 12, 8, 20))
{
}

std::string Warrior::getClassName() const {
    return "Warrior";
}

void Warrior::attack(Entity& target) {
    Hero::attack(target);
}

void Warrior::useSkill(Entity& target) {
    cout << name_ << " uses Berserk!\n";
    stats_.takeDamage(10);
    Hero::attack(target);
    Hero::attack(target);
}

void Warrior::displayStats() const {
    Hero::displayStats();
}
