#pragma once
#include "Hero.h"
#include <string>

class Mage : public Hero {
public:
    explicit Mage(const std::string& name);
    virtual ~Mage() = default;

    void useSkill(Entity& target) override;
    std::string getType() const override;
    void levelUp() override;
};
