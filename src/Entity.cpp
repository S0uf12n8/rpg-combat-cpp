#include "Entity.h"
#include <iostream>
using namespace std;

Entity::Entity(const std::string& name, const Stats& stats)
    : name_(name), stats_(stats) {}

Entity::~Entity() {
    for (Skill* s : skills_) {
        delete s;
    }
}

void Entity::takeDamage(int raw) {
    stats_.takeDamage(raw);
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

void Entity::tryUseSkill(int index, Entity& target) {
    if (index < 0 || index >= (int)skills_.size()) return;

    Skill* skill = skills_[index];
    if (stats_.getMana() < skill->getManaCost()) {
        cout << name_ << " not enough mana for " << skill->getName() << "!\n";
        return;
    }

    stats_.spendMana(skill->getManaCost());
    skill->use(*this, target);
}
