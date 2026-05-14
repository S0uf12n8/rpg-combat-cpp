#include "Burn.h"
#include "Entity.h"

Burn::Burn(const std::string& name, int duration):
StatusEffect(name,duration), buring(2){}

void Burn::onTurnStart(Entity& target){
    target.takeDamage(target.getHp()*0.02);
    duration--;
}

void Burn::onTurnEnd(Entity& target){}

bool Burn::isExpired()const{
    return duration<=0;
}

std::string Burn::getName() const{
    return name;
}