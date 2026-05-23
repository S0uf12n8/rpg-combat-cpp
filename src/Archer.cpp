#include "Archer.h"
#include <iostream>
#include <cstdlib>

using namespace std;

PiercingArrow::PiercingArrow()
    : Skill("piercing arrow", 20, 40, "fast arrow with crit chance.")
{}

void PiercingArrow::use(Entity& caster, Entity& target) const {
    cout << caster.getName() << " fires a piercing arrow!\n";
    bool crit = (rand() % 100) < 30;
    int dmg = crit ? power_ * 2 : power_;
    if (crit) cout << "  *** crit hit! ***\n";
    target.takeDamage(dmg);
}

Archer::Archer(const string& name)
    : Hero(name, Stats(110, 26, 9, 18, 60)) {
    skills_.push_back(new PiercingArrow());
}

string Archer::getClassName() const {
    return "Archer";
}

void Archer::attack(Entity& target) {
    bool crit = (rand() % 100) < 20;
    int dmg = crit ? stats_.getAttack() * 2 : stats_.getAttack();
    cout << name_ << " fires quick shot at " << target.getName() << "!";
    if (crit) cout << " *** crit! ***";
    cout << "\n";
    target.takeDamage(dmg);
}

void Archer::useSkill(Entity& target) {
    tryUseSkill(0, target);
}

void Archer::levelUp() {
    Hero::levelUp();
    stats_.setSpeed(stats_.getSpeed() + 3);
    stats_.setAttack(stats_.getAttack() + 4);
    cout << name_ << "'s reflexes sharpened!\n";
}
