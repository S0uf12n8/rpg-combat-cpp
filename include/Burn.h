#pragma once
#include "StatusEffect.h"

class Burn : public StatusEffect{
public: 
    Burn(const std::string& name, int duration);

    void onTurnStart(Entity& target) override;
    void onTurnEnd(Entity& target) override;
    bool isExpired()const override;
    std::string getName() const override;
private:
    int buring ;
};