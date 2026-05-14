#pragma once
#include "StatusEffect.h"

class Poison:public StatusEffect{
public:
    Poison(const std::string& name, int duration);
    void onTurnStart(Entity& target) override;
    void onTurnEnd(Entity& target) override;
    bool isExpired() const override;
    std::string getName() const override;
private:
    int poisoning;
};