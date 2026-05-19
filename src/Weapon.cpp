#include "Weapon.h"
#include <iostream>
using namespace std;

Weapon::Weapon(const std::string& name,
               const std::string& description,
               int value,
               int attackBonus)
    : Item(name, description, value), attackBonus(attackBonus) {}

void Weapon::use() {
    cout << "You equip [" << getName() << "]!\n";
}

int Weapon::getAttackBonus() const {
    return attackBonus;
}

std::string Weapon::getDescription() const {
    return getName() + " -- ATK +" + std::to_string(getAttackBonus());
}