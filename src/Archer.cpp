#include "Archer.h"
#include <iostream>
#include <cstdlib>


PiercingArrow::PiercingArrow()
    : Skill("Piercing Arrow", /*manaCost=*/20, /*power=*/40, "A swift arrow with a 30% critical hit chance for double damage.")
{}

void PiercingArrow::use(Entity& caster, Entity& target) const {
    cout << caster.getName() << " notches and fires a PIERCING ARROW!\n";

    bool isCritical = (rand() % 100) < 30;
    int  damage     = isCritical ? power_ * 2 : power_;

    if (isCritical) {
        cout << "  *** CRITICAL HIT! ***\n";
    }

    target.takeDamage(damage);
}


Archer::Archer(const string& name)
    : Hero(name, Stats(/*maxHP=*/110, /*atk=*/26, /*def=*/9, /*spd=*/18, /*mana=*/60))
{
    skills_.push_back(new PiercingArrow());
}

void Archer::attack(Entity& target) {
    bool isCritical = (rand() % 100) < 20;
    int  damage     = isCritical ? stats_.getAttack() * 2 : stats_.getAttack();

    cout << name_ << " fires a quick shot at " << target.getName() << "!";
    if (isCritical) cout << " *** CRITICAL! ***";
    cout << "\n";

    target.takeDamage(damage);
}

void Archer::useSkill(Entity& target) {
    tryUseSkill(0, target);
}

void Archer::levelUp() {
    Hero::levelUp();
    stats_.setSpeed(stats_.getSpeed() + 3);
    stats_.setAttack(stats_.getAttack() + 4);
    cout << name_ << "'s reflexes sharpened — speed and attack increased!\n";
}
