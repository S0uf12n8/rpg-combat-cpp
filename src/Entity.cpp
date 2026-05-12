#include "Entity.h"
#include <iostream>

Entity::Entity(const std::string& name, const Stats& stats)
    : name_(name), stats_(stats)
{}


void Entity::takeDamage(int rawDamage) {
    stats_.takeDamage(rawDamage);
}

bool Entity::isAlive() const {
    return !stats_.isDead();
}

void Entity::displayStats() const {
    std::cout << "  [" << name_ << "]"
              << "  HP: "  << stats_.getCurrentHP() << "/" << stats_.getMaxHP()
              << "  MP: "  << stats_.getMana()       << "/" << stats_.getMaxMana()
              << "  ATK: " << stats_.getAttack()
              << "  DEF: " << stats_.getDefense()
              << "  SPD: " << stats_.getSpeed()
              << "\n";
}

const std::string& Entity::getName()  const { return name_; }
const Stats&       Entity::getStats() const { return stats_; }
Stats&             Entity::getStats()       { return stats_; }

void Entity::tryUseSkill(int index, Entity& target) {
    if (index < 0 || index >= static_cast<int>(skills_.size())) return;

    Skill* skill = skills_[index].get(); // .get() to borrow raw pointer without releasing ownership

    if (stats_.getMana() < skill->getManaCost()) {
        std::cout << name_ << " doesn't have enough mana for "
                  << skill->getName() << "!\n";
        return;
    }

    stats_.spendMana(skill->getManaCost());
    skill->use(*this, target);
}