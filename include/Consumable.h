#pragma once
#include "Item.h"

// Consumable = potions, food— anything you "drink" or "eat"
class Consumable : public Item {
private:
    int healAmount; 

public:
    // Constructor: we need name, description, value (for Item)
    Consumable(const std::string& name,
               const std::string& description,
               int value,
               int healAmount);

    // Override use() — this is what happens when player drinks a potion
    void use() override;

    int getHealAmount() const;
};