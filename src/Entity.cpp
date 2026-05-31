#include "Entity.h"
#include <iostream>
#include <algorithm>

Entity::Entity(const std::string& name, const Stats& stats)
    : name_(name), stats_(stats)
{
}

void Entity::addEffect(std::unique_ptr<StatusEffect> effect) {
    activeEffects_.push_back(std::move(effect));
}

void Entity::applyAndTickEffects() {
    for (auto& effect : activeEffects_)
        effect->applyEffect(*this);
    for (auto& effect : activeEffects_)
        effect->tick();
    activeEffects_.erase(
        std::remove_if(activeEffects_.begin(), activeEffects_.end(),
            [](const std::unique_ptr<StatusEffect>& e) { return e->isExpired(); }),
        activeEffects_.end());
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

