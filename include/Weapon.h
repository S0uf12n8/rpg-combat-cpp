#pragma once
#include "Item.h"

class Weapon : public Item {
private:
    int attackBonus;
public:
    Weapon(const std::string& name,
           const std::string& description,
           int value,
           int attackBonus);

    void use() override;
    int getAttackBonus() const;
    std::string getDescription() const override;
};
