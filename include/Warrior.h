#pragma once
#include "Hero.h"
#include <string>

class Warrior : public Hero {
public:
    explicit Warrior(const std::string& name);
    virtual ~Warrior() = default;

    void useSkill(Entity& target) override;
    std::string getType() const override;
    void levelUp() override;
};
