#include "StatusEffect.h"

StatusEffect::StatusEffect(int duration){
    
    this->duration=duration;
}
bool StatusEffect::isExpired()const{
    return duration<=0;
}
void StatusEffect::tick(){
    duration--;
}

