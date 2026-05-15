#pragma once
#include "StatusEffect.h"

class Poison:public StatusEffect{
public:
    Poison();
    
    void applyEffect(Entity& target) override;
    std::string getName() const override;
};