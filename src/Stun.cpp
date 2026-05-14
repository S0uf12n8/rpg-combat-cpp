#include "Stun.h"
#include "Entity.h"

Stun::Stun(const std::string& name, int duration):
StatusEffect(name, duration), freezeturn(true){}

void Stun::onTurnStart(Entity& target){
    target.setStunned(true);
    duration--;
}

void Stun::onTurnEnd(Entity& target){}

bool Stun::isExpired() const{
    return duration <= 0;
}

std::string Stun::getName() const{
    return name;
}