#ifndef ARCHER_H
#define ARCHER_H

#include "Hero.h"
#include <cstdlib> 

class Archer : public Hero {
public:
    explicit Archer(const string& name);

    void attack(Entity& target);
    void useSkill(Entity& target);

    void levelUp();
};

class PiercingArrow : public Skill {
public:
    PiercingArrow();
    void use(Entity& caster, Entity& target) const;
};

#endif 