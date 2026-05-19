#include "Warrior.h"
#include <iostream>

using namespace std;

Warrior::Warrior(const string& name)
    : Hero(name, Stats(120, 18, 12, 7, 20)) {}

string Warrior::getType() const {
    return "Warrior";
}

void Warrior::useSkill(Entity& target) {
    if (stats_.getCurrentHP() <= 10) {
        cout << "Not enough HP for Berserk!\n";
        return;
    }

    cout << name_ << " uses Berserk!\n";
    
    // Costs 10 HP to self (ignores self defense)
    this->takeDamage(10 + stats_.getDefense());

    // Attack the target twice using stats_.getAttack() raw damage formula
    for (int i = 0; i < 2; ++i) {
        if (target.isAlive()) {
            int hpBefore = target.getStats().getCurrentHP();
            target.takeDamage(stats_.getAttack());
            int damageDealt = hpBefore - target.getStats().getCurrentHP();
            cout << "  Hit " << (i + 1) << " deals " << damageDealt << " damage!\n";
        }
    }
}

void Warrior::levelUp() {
    Hero::levelUp();
    stats_.setMaxHP(stats_.getMaxHP() + 25);
    stats_.heal(25);
    stats_.setAttack(stats_.getAttack() + 4);
    stats_.setDefense(stats_.getDefense() + 3);
    stats_.setSpeed(stats_.getSpeed() + 1);
    stats_.setMaxMana(stats_.getMaxMana() + 2);
    stats_.restoreMana(2);
    cout << name_ << " leveled up! Stronger and tougher!\n";
}
