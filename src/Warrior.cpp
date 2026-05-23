#include "Warrior.h"
#include <iostream>
using namespace std;

PowerSlash::PowerSlash()
    : Skill("Power Slash", /*manaCost=*/0, /*power=*/55, "A heavy blow that bypasses part of the target's defense.")
{}

void PowerSlash::use(Entity& caster, Entity& target) const {
    cout << caster.getName() << " charges and delivers a POWER SLASH!\n";
    target.takeDamage(power_);
}

Warrior::Warrior(const string& name)
    : Hero(name, Stats(160, 22, 14, 7, 0))
{
    skills_.push_back(new PowerSlash());
}

std::string Warrior::getClassName() const {
    return "Warrior";
}

void Warrior::attack(Entity& target) {
    Hero::attack(target);
}

void Warrior::useSkill(Entity& target) {
    tryUseSkill(0, target);
}

void Warrior::levelUp() {
    Hero::levelUp();
    stats_.setMaxHP(stats_.getMaxHP() + 10);
    stats_.heal(10);
    stats_.setDefense(stats_.getDefense() + 3);
    cout << name_ << "'s warrior training boosted HP and defense further!\n";
}

void Warrior::displayStats() const {
    Hero::displayStats();
}
