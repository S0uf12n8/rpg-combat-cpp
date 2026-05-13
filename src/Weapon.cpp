#include "Weapon.h"
#include "Entity.h"
#include <iostream>

Weapon::Weapon(const std::string& name,
const std::string& description,
int value,
int attackBonus,
int durability) : attackBonus(attackBonus), durability(durability)
{
    this->name        = name;
    this->description = description;
    this->value       = value;
}

void Weapon::degradeOnHit() {
    if (durability > 0) {
        durability--;
        if (durability == 0) {
            std::cout << name << " has broken\n";
        }
    }
}

std::string Weapon::getName()  const { return name; }
int Weapon::getValue() const { return value; }
int Weapon::getAttackBonus() const { return attackBonus; }
int Weapon::getDurability()  const { return durability; }

std::string Weapon::getDescription() const {
    return name + " | ATK +" + std::to_string(attackBonus) + " | Durability: " + std::to_string(durability);
}

Sword::Sword(): Weapon("Gram", "A legendary sword forged by the gods", 150, 25, 80)
{}

void Sword::use(Entity& target) {
    std::cout << "You slash with Gram dealing " << attackBonus << " damage\n";
    target.takeDamage(attackBonus);
    degradeOnHit();
}


Bow::Bow(): Weapon("Hunter Bow", "A carved yew bow from the Norse forests", 120, 18, 999),arrowCount(30)
{}

void Bow::use(Entity& target) {
    if (arrowCount <= 0) {
        std::cout << "No arrow left\n";
        return;
    }
    arrowCount--;
    std::cout << "You fire an arrow dealing " << attackBonus
              << " damage (" << arrowCount << " arrows left)\n";
    target.takeDamage(attackBonus);
}

int Bow::getArrowCount() const { return arrowCount; }

Staff::Staff() : Weapon("Seidr Staff","A runic staff carved from Yggdrasil wood",130, 10, 60),magicBonus(20)
{}

void Staff::use(Entity& target) {
    std::cout << "You strike with the Seidr Staff dealing "
              << attackBonus << " damage\n"
              << "(Magic skills get +" << magicBonus << " bonus)\n";
    target.takeDamage(attackBonus);
    degradeOnHit();
}

int Staff::getMagicBonus() const { return magicBonus; }


Mjolnir::Mjolnir() : Weapon("Mjolnir","Thor's divine hammer — most feared in the nine realms", 999, 50, 200)
{}

void Mjolnir::use(Entity& target) {
    std::cout << "MJOLNIR strikes " << target.getName()
              << " with divine thunder " << attackBonus << " damage\n"
              << target.getName() << " is STUNNED\n";
    target.takeDamage(attackBonus);
    degradeOnHit();
}