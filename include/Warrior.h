#ifndef WARRIOR_H
#define WARRIOR_H

// ============================================================
//  Warrior.h
//  Concrete playable class: melee fighter.
//
//  Stats profile:
//    - High HP, high defense
//    - Medium attack
//    - Low speed, no mana
//
//  Signature skill: Power Slash — a heavy, armor-ignoring blow.
// ============================================================

#include "Hero.h"

// ---- Warrior class ----
class Warrior : public Hero {
public:
    explicit Warrior(const string& name);

    void attack(Entity& target);
    void useSkill(Entity& target);

    // Warrior-specific level-up: boosts HP and defense more than base.
    void levelUp();
};

// ---- Warrior's signature skill ----
// Declared after Warrior so the class comes first, as per convention.
class PowerSlash : public Skill {
public:
    PowerSlash();
    // Ignores a portion of the target's defense (armor-piercing).
    void use(Entity& caster, Entity& target) const;
};

#endif // WARRIOR_H
