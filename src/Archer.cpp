#include "Archer.h"
#include <iostream>

using namespace std;

Archer::Archer(const string& name)
    : Hero(name, Stats(90, 14, 8, 11, 40)) {}

string Archer::getClassName() const {
    return "Archer";
}

void Archer::useSkill(Entity& target) {
    if (stats_.getMana() < 15) {
        cout << "Not enough mana!\n";
        return;
    }

    cout << name_ << " uses Precise Shot!\n";
    stats_.spendMana(15);
    target.takeDamage(stats_.getAttack());
}
