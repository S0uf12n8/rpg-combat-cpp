#include "Consumable.h"
#include <iostream>

// We use Item(...) to call the parent constructor first
Consumable::Consumable(const std::string& name,
                       const std::string& description,
                       int value,
                       int healAmount)
    : Item(name, description, value), healAmount(healAmount)
{
}

// When Oussama's Combat class calls item->use(), this function runs
void Consumable::use() {
    std::cout << "You drink " << getName()
              << " and restore " << healAmount << " HP!\n";
}

int Consumable::getHealAmount() const {
    return healAmount;
}