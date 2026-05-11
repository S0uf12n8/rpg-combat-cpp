#ifndef ARCHER_H
#define ARCHER_H

// ============================================================
//  Archer.h
//  Concrete playable class: fast ranged attacker.
//
//  Stats profile:
//    - Medium HP, medium defense
//    - High speed (attacks first in combat ordering)
//    - Balanced attack + critical-hit style gameplay
//
//  Signature skill: Piercing Arrow — 30% critical hit chance.
// ============================================================

#include "Hero.h"
#include <cstdlib> // rand()

// ---- Archer class ----
class Archer : public Hero {
public:
    explicit Archer(const string& name);

    void attack(Entity& target);
    void useSkill(Entity& target);

    // Archer-specific level-up: boosts speed and attack more than base.
    void levelUp();
};

// ---- Archer's signature skill ----
// Declared after Archer so the class comes first, as per convention.
class PiercingArrow : public Skill {
public:
    PiercingArrow();
    // 30% chance to deal double damage (critical hit).
    void use(Entity& caster, Entity& target) const;
};

#endif // ARCHER_H