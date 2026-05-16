#ifndef ARCHER_H
#define ARCHER_H

#include "Hero.h"

class PiercingArrow : public Skill {
public:
    PiercingArrow();
    void use(Entity& caster, Entity& target) const override;
};

class Archer : public Hero {
public:
    explicit Archer(const string& name);

    void attack(Entity& target) override;
    void useSkill(Entity& target) override;
    void levelUp() override;
};

#endif
