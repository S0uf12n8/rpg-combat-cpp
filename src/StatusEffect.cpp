#include "StatusEffect.h"

StatusEffect::StatusEffect(const std::string& name, int duration){
    this->name=name;
    this->duration=duration;
}
std::string StatusEffect::getName()const{
    return name;
}