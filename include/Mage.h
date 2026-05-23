#pragma once
#include "Hero.h"

class Mage : public Hero {
public:
    explicit Mage(const std::string& name);
    void attack(Entity& target) override;
    void useSkill(Entity& target) override;
    std::string getClassName() const override;
    void displayStats() const override;
};
