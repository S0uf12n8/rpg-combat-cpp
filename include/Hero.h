#pragma once
#include "Entity.h"
#include <string>
#include <vector>

class Item;
class Weapon;
class Armor;

class Hero : public Entity {
protected:
    int level;
    int xp;
    int xpToNext;
    std::vector<Item*> inventory;   // max 5 items
    Weapon* equippedWeapon;
    Armor*  equippedArmor;

public:
    Hero(const std::string& name, const Stats& stats);
    virtual ~Hero() = default;

    // Still abstract — each subclass defines its own skill
    virtual void useSkill(Entity& target) = 0;
    virtual std::string getType() const = 0;

    int  attack(Entity& target) override; // base attack + weapon bonus, deals damage to target
    void gainXP(int amount);
    virtual void levelUp();                // called automatically when xp >= xpToNext
    bool addItem(Item* item);              // returns false if inventory full (max 5)
    void equipWeapon(Weapon* w);           // sets equippedWeapon, adds attackBonus to stats
    void equipArmor(Armor* a);             // sets equippedArmor, adds defenseBonus to stats
    int  getLevel() const;
    std::vector<Item*>& getInventory();
};
