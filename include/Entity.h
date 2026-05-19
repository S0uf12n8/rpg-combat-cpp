#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include <vector>
#include "Stats.h"

class Entity {
protected:
    std::string name_;
    Stats  stats_;

public:
    Entity(const std::string& name, const Stats& stats);
    virtual ~Entity() = default;

    virtual int attack(Entity& target)   = 0;
    virtual void useSkill(Entity& target) = 0;
    virtual std::string getType() const  = 0;

    void takeDamage(int raw);
    bool isAlive() const;
    virtual void displayStats() const;

    const std::string& getName()  const;
    const Stats&  getStats() const;
    Stats&        getStats();
};

#endif
