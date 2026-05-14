#include "Poison.h"
#include "Entity.h"
Poison::Poison(const std::string& name, int duration)
:StatusEffect(name,duration),poisoning(5){}

void Poison::onTurnStart(Entity& target){
    target.takeDamage(target.getHp()*0.05);
    duration--;
}

void Poison::onTurnEnd(Entity& target){}

bool Poison::isExpired()const{
    return duration<=0;
}

std::string Poison::getName() const{
    return name;
}