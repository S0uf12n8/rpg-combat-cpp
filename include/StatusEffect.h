#pragma once
#include <string>

class Entity; 

class StatusEffect {
public:
    
    StatusEffect(const std::string& name, int duration);
    
    virtual ~StatusEffect() = default;

    virtual void onTurnStart(Entity& target) = 0;
    virtual void onTurnEnd(Entity& target) = 0;
    virtual bool isExpired() const = 0;
    virtual std::string getName() const = 0;

protected:
    std::string name;   
    int duration;           
};