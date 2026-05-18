#pragma once
#include "Hero.h"

class Warrior : public Hero {
public:
    explicit Warrior(const std::string& name);
    void attack(Entity& target) override;
    void useSkill(Entity& target) override;
    std::string getClassName() const override;
    void displayStats() const override;
};
