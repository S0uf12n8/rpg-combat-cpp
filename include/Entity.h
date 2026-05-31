#pragma once
#include <string>
#include <vector>
#include <memory>
#include "Stats.h"
#include "StatusEffect.h"

class Entity {
protected:
    std::string name_;
    Stats       stats_;
    std::vector<std::unique_ptr<StatusEffect>> activeEffects_;

public:
    Entity(const std::string& name, const Stats& stats);
    virtual ~Entity() = default;

    Entity(const Entity&)            = delete;
    Entity& operator=(const Entity&) = delete;

    virtual void attack(Entity& target)   = 0;
    virtual void useSkill(Entity& target) = 0;

    void addEffect(std::unique_ptr<StatusEffect> effect);
    void applyAndTickEffects();

    void takeDamage(int rawDamage);
    bool isAlive() const;

    virtual void displayStats() const;

    const std::string& getName()  const;
    const Stats&       getStats() const;
    Stats&             getStats();
};