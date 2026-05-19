#pragma once
#include "Entity.h"
#include <string>

class Enemy : public Entity {
private:
    std::string dropItem;   // name of item to drop e.g. "Health Potion"
    int dropChance;         // 0-100 percent
    int xpReward;
public:
    Enemy(const std::string& name, const Stats& stats,
          const std::string& drop, int dropChance, int xp);
    virtual ~Enemy() = default;

    int attack(Entity& target) override;
    void useSkill(Entity& target) override;
    std::string getType() const override;
    std::string tryDrop() const;   // returns dropItem name or "" based on dropChance
    int getXPReward() const;
};
