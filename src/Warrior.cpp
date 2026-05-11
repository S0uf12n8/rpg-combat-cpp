// ============================================================
//  Warrior.cpp
//  Implementation of the Warrior class and its PowerSlash skill.
// ============================================================

#include "Warrior.h"
#include <iostream>
#include <algorithm>

// ---- PowerSlash implementation ----

PowerSlash::PowerSlash()
    : Skill("Power Slash", /*manaCost=*/0, /*power=*/55, "A heavy blow that bypasses part of the target's defense.")
{}

void PowerSlash::use(Entity& caster, Entity& target) const {
    cout << caster.getName() << " charges and delivers a POWER SLASH!\n";
    // Armor-piercing: bypass defense by adding it back so Stats' reduction cancels it out.
    int piercing = power_ + target.getStats().getDefense();
    target.takeDamage(piercing);
}

// ---- Warrior implementation ----

Warrior::Warrior(const string& name)
    : Hero(name, Stats(/*maxHP=*/160, /*atk=*/22, /*def=*/14, /*spd=*/7))
{
    // Register signature skill using a raw pointer (new).
    // The Entity destructor is responsible for calling delete on this pointer.
    skills_.push_back(new PowerSlash());
}

void Warrior::attack(Entity& target) {
    cout << name_ << " swings his sword at " << target.getName() << "!\n";
    target.takeDamage(stats_.getAttack());
}

void Warrior::useSkill(Entity& target) {
    tryUseSkill(0, target); // Index 0 = PowerSlash
}

void Warrior::levelUp() {
    Hero::levelUp(); // Call base level-up first
    // Warrior bonus: extra HP and defense growth
    stats_.setMaxHP(stats_.getMaxHP() + 10);
    stats_.heal(10);
    stats_.setDefense(stats_.getDefense() + 3);
    cout << name_ << "'s warrior training boosted HP and defense further!\n";
}
