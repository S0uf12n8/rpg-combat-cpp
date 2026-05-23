#include "Stats.h"
#include <algorithm>
#include <ostream>

Stats::Stats(int maxHP, int attack, int defense, int speed, int mana)
    : maxHP_(maxHP),
      currentHP_(maxHP),
      attack_(attack),
      defense_(defense),
      speed_(speed),
      mana_(mana),
      maxMana_(mana)
{}

int Stats::getMaxHP()     const { return maxHP_; }
int Stats::getCurrentHP() const { return currentHP_; }
int Stats::getAttack()    const { return attack_; }
int Stats::getDefense()   const { return defense_; }
int Stats::getSpeed()     const { return speed_; }
int Stats::getMana()      const { return mana_; }
int Stats::getMaxMana()   const { return maxMana_; }

void Stats::setAttack(int value)  { attack_  = std::max(0, value); }
void Stats::setDefense(int value) { defense_ = std::max(0, value); }
void Stats::setSpeed(int value)   { speed_   = std::max(0, value); }
void Stats::setMana(int value)    { mana_    = std::max(0, std::min(maxMana_, value)); }
void Stats::setMaxHP(int value) {
    maxHP_ = std::max(1, value);
    currentHP_ = std::min(currentHP_, maxHP_);
}
void Stats::setMaxMana(int value) {
    maxMana_ = std::max(0, value);
    mana_ = std::min(mana_, maxMana_);
}

int Stats::calculateReducedDamage(int rawDamage) const {
    return std::max(1, rawDamage - defense_);
}

void Stats::takeDamage(int amount) {
    currentHP_ = std::max(0, currentHP_ - amount);
}

void Stats::heal(int amount) {
    currentHP_ = std::min(maxHP_, currentHP_ + amount);
}

void Stats::spendMana(int amount) {
    mana_ = std::max(0, mana_ - amount);
}

void Stats::restoreMana(int amount) {
    mana_ = std::min(maxMana_, mana_ + amount);
}

bool Stats::isDead() const {
    return currentHP_ <= 0;
}

std::ostream& operator<<(std::ostream& os, const Stats& s) {
    os << "HP: "  << s.currentHP_ << "/" << s.maxHP_
       << " | ATK: " << s.attack_
       << " | DEF: " << s.defense_
       << " | SPD: " << s.speed_
       << " | MP: "  << s.mana_ << "/" << s.maxMana_;
    return os;
}
