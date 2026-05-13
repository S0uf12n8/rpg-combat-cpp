#pragma once
#include "Item.h"
#include <string>

class Weapon : public Item {
protected:
    int attackBonus;
    int durability;

public:
    Weapon(const std::string& name,
           const std::string& description,
           int value,
           int attackBonus,
           int durability);

    void degradeOnHit();

    int getAttackBonus() const;
    int getDurability()  const;
    std::string getName() const override;
    std::string getDescription() const override;
    int getValue() const override;

    void use(Entity& target) override = 0;
};

class Sword : public Weapon {
public:
    Sword();
    void use(Entity& target) override;
};

class Bow : public Weapon {
private:
    int arrowCount;

public:
    Bow();
    void use(Entity& target) override;
    int getArrowCount() const;
};

class Staff : public Weapon {
private:
    int magicBonus;

public:
    Staff();
    void use(Entity& target) override;
    int getMagicBonus() const;
};


class Mjolnir : public Weapon {
public:
    Mjolnir();
    void use(Entity& target) override;
};