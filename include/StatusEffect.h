#pragma once
#include <string>

class Entity; 

class StatusEffect {
protected:   
    int duration;

public:
    
    StatusEffect(int duration);
    
    virtual ~StatusEffect() = default;

    virtual void applyEffect(Entity& target) = 0; 
    virtual std::string getName() const = 0;  
    bool isExpired() const;
    void tick();         
};