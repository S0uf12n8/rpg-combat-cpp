#include "Stun.h"
#include "Entity.h"
#include <iostream>

Stun::Stun():StatusEffect(1){}

void Stun::applyEffect(Entity& target){
    std::cout<<target.getName()<<" is stunned and cannot act!";
}
std::string Stun::getName() const{
    return "Stun";
}