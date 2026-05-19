#pragma once
#include "Hero.h"
#include <string>

class Archer : public Hero {
public:
    explicit Archer(const std::string& name);
    virtual ~Archer() = default;

    void useSkill(Entity& target) override;
    std::string getType() const override;
    void levelUp() override;
};
