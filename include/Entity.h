#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include <vector>
#include "Stats.h"
#include "Skill.h"
using namespace std;

class Entity {
protected:
    string name_;
    Stats  stats_;
    vector<Skill*> skills_;

    void tryUseSkill(int index, Entity& target);

public:
    Entity(const string& name, const Stats& stats);
    virtual ~Entity();

    virtual void attack(Entity& target)   = 0;
    virtual void useSkill(Entity& target) = 0;

    void takeDamage(int raw);
    bool isAlive() const;
    virtual void displayStats() const;

    const string& getName()  const;
    const Stats&  getStats() const;
    Stats&        getStats();
};

#endif
