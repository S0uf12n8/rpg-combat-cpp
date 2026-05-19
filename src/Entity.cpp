#include "Entity.h"
#include <iostream>

using namespace std;

Entity::Entity(const string& name, const Stats& stats)
    : name_(name), stats_(stats) {}

void Entity::takeDamage(int raw) {
    stats_.takeDamage(raw);
}

bool Entity::isAlive() const {
    return !stats_.isDead();
}

void Entity::displayStats() const {
    cout << "  [" << name_ << "]"
         << "  hp: " << stats_.getCurrentHP() << "/" << stats_.getMaxHP()
         << "  mp: " << stats_.getMana()      << "/" << stats_.getMaxMana()
         << "  atk: " << stats_.getAttack()
         << "  def: " << stats_.getDefense()
         << "  spd: " << stats_.getSpeed() << "\n";
}

const string& Entity::getName()  const { return name_; }
const Stats&  Entity::getStats() const { return stats_; }
Stats&        Entity::getStats()       { return stats_; }
