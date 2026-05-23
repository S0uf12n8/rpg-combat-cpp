#pragma once
#include "Hero.h"
#include <string>

class PowerSlash : public Skill {
public:
    PowerSlash();
    void use(Entity& caster, Entity& target) const override;
};

class Warrior : public Hero {
public:
    explicit Warrior(const std::string& name);
    virtual ~Warrior() = default;

    void attack(Entity& target) override;
    void useSkill(Entity& target) override;
    void levelUp() override;
    std::string getClassName() const override;
    void displayStats() const override;
};
