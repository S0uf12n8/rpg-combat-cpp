#include "Hero.h"
#include "Weapon.h"
#include "Armor.h"
#include <iostream>
#include <cstdlib>
using namespace std;

Hero::Hero(const std::string& name, const Stats& stats)
    : Entity(name, stats),
      level_(1),
      xp_(0),
      xpToNext_(100),
      equippedWeapon_(nullptr),
      equippedArmor_(nullptr)
{
}

void Hero::attack(Entity& target) {
    int rawDamage = stats_.getAttack() + (rand() % 5 - 2);
    int damage = target.getStats().calculateReducedDamage(rawDamage);
    target.takeDamage(damage);
    cout << name_ << " attacks " << target.getName()
         << " for " << damage << " damage!\n";
}

void Hero::gainXP(int amount) {
    xp_ += amount;
    if (xp_ >= xpToNext_) {
        levelUp();
    }
}

void Hero::levelUp() {
    level_++;
    xpToNext_ *= 2;
    stats_.setAttack(stats_.getAttack() + 2);
    stats_.setDefense(stats_.getDefense() + 1);
    cout << name_ << " leveled up! Now level " << level_ << "!\n";
}

bool Hero::addItem(Item* item) {
    return inventory_.addItem(item);
}

void Hero::equipWeapon(Weapon* w) {
    if (equippedWeapon_)
        stats_.setAttack(stats_.getAttack() - equippedWeapon_->getAttackBonus());
    equippedWeapon_ = w;
    stats_.setAttack(stats_.getAttack() + w->getAttackBonus());
    cout << name_ << " equipped " << w->getName() << "!\n";
}

void Hero::equipArmor(Armor* a) {
    if (equippedArmor_)
        stats_.setDefense(stats_.getDefense() - equippedArmor_->getDefenseBonus());
    equippedArmor_ = a;
    stats_.setDefense(stats_.getDefense() + a->getDefenseBonus());
    cout << name_ << " equipped " << a->getName() << "!\n";
}

int Hero::getLevel() const {
    return level_;
}

Weapon* Hero::getEquippedWeapon() const {
    return equippedWeapon_;
}

Armor* Hero::getEquippedArmor() const {
    return equippedArmor_;
}

Inventory& Hero::getInventory() {
    return inventory_;
}

void Hero::displayStats() const {
    cout << "Class: " << getClassName() << "  Level: " << level_ << "\n";
    Entity::displayStats();
}
