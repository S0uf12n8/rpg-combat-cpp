#include "Armor.h"
#include <iostream>

Armor::Armor(const std::string& name,
             const std::string& description,
             int value,
             int defenseBonus)
    : Item(name, description, value), defenseBonus(defenseBonus)
{}

void Armor::use() {
    std::cout << "You equip " << getName()
              << " (+" << defenseBonus << " defense).\n";
}

std::string Armor::getDescription() const {
    return getName() + " — DEF +" + std::to_string(defenseBonus);
}

int Armor::getDefenseBonus() const { return defenseBonus; }