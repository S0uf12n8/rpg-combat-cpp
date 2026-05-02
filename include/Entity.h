#pragma once
#include <string>
#include <vector>
#include <memory>

class StatusEffect; 

class Entity {
public:
    virtual ~Entity() = default;

    virtual void attack(Entity& target) = 0;
    virtual void takeDamage(int amount) = 0;
    virtual void heal(int amount) = 0;
    virtual bool isAlive() const = 0;

    virtual std::string getName() const = 0;
    virtual int getHP() const = 0;
    virtual int getMaxHP() const = 0;
    virtual int getAttack() const = 0;
    virtual int getDefense() const = 0;

    // Status effects — Oussama uses these
    void addEffect(std::shared_ptr<StatusEffect> effect);
    void processEffects();
    void clearEffects();

protected:
    std::string name;
    int hp, maxHp, attackPower, defense;
    std::vector<std::shared_ptr<StatusEffect>> activeEffects;
};