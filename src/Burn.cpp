#include "Burn.h"
#include "Entity.h"
#include <iostream>

Burn::Burn():StatusEffect(3){}

void Burn::applyEffect(Entity& target){
    target.takeDamage(8);
    
    std::cout<<target.getName()<<" is burning and takes 8 damage!";
}


std::string Burn::getName() const{
    return "Burn";
}