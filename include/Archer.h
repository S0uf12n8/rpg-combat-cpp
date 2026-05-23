#pragma once
#include "Hero.h"
#include <string>

class PiercingArrow : public Skill {
public:
    PiercingArrow();
    void use(Entity& caster, Entity& target) const override;
};

class Archer : public Hero {
public:
    explicit Archer(const std::string& name);
    virtual ~Archer() = default;

    void attack(Entity& target) override;
    void useSkill(Entity& target) override;
    void levelUp() override;
    std::string getClassName() const override;
};
