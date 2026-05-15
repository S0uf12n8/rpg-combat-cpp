#pragma once
#include "StatusEffect.h"

class Stun:public StatusEffect{
public:
    Stun();

    void applyEffect(Entity& target) override;
    std::string getName() const override;
};