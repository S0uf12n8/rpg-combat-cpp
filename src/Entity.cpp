#include "Entity.h"
#include <iostream>

Entity::Entity(const std::string& name, const Stats& stats)
    : name_(name), stats_(stats)
{
}

void Entity::takeDamage(int rawDamage) {
    stats_.takeDamage(rawDamage);
}

bool Entity::isAlive() const {
    return !stats_.isDead();
}

void Entity::displayStats() const {
    std::cout << name_ << "\n" << stats_ << "\n";
}

const std::string& Entity::getName() const {
    return name_;
}

const Stats& Entity::getStats() const {
    return stats_;
}

Stats& Entity::getStats() {
    return stats_;
}

