#pragma once
#include "StatusEffect.h"

class Burn : public StatusEffect{
public: 
    Burn();

    void applyEffect(Entity& target) override;
    std::string getName() const override;
};