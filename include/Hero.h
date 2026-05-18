#pragma once
#include "Entity.h"
#include "Inventory.h"
#include <string>

class Weapon;
class Armor;

class Hero : public Entity {
protected:
    int level_;
    int xp_;
    int xpToNext_;
    Inventory inventory_;
    Weapon* equippedWeapon_;
    Armor*  equippedArmor_;
public:
    Hero(const std::string& name, const Stats& stats);
    virtual ~Hero() = default;
    virtual void attack(Entity& target) override;
    virtual void useSkill(Entity& target) = 0;
    virtual std::string getClassName() const = 0;
    void gainXP(int amount);
    void levelUp();
    bool addItem(Item* item);
    void equipWeapon(Weapon* w);
    void equipArmor(Armor* a);
    int getLevel() const;
    Weapon* getEquippedWeapon() const;
    Armor*  getEquippedArmor()  const;
    Inventory& getInventory();
    virtual void displayStats() const override;
};
