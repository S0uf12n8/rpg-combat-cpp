#pragma once
#include "Item.h"

// Armor = anything that reduces incoming damage

class Armor : public Item {
private:
    int defenseBonus; // damage reduction

public:
    Armor(const std::string& name,
          const std::string& description,
          int value,
          int defenseBonus);

    void use() override;

    int getDefenseBonus() const;

    std::string getDescription() const override;
};