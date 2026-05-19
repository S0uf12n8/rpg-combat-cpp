#pragma once
#include "Entity.h"
#include <string>

class Enemy : public Entity {
private:
    std::string dropItem;
    int dropChance;
    int xpReward;

public:
    Enemy(const std::string& name, const Stats& stats,
          const std::string& drop, int dropChance, int xp);
    virtual ~Enemy() = default;

    void attack(Entity& target) override;
    void useSkill(Entity& target) override;

    std::string tryDrop() const;

    int getXPReward() const;
    int getDropChance() const;
    std::string getDropItemName() const;
};
