#include "Poison.h"
#include "Entity.h"
#include <iostream>
Poison::Poison():StatusEffect(3){}

void Poison::applyEffect(Entity& target){
    target.takeDamage(5);
    
    std::cout<<target.getName()<<" is poisoned and takes 5 damage!";
}


std::string Poison::getName() const{
    return "Poison";
}