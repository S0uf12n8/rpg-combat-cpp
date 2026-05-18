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
{
}

int Stats::getMaxHP()     const { return maxHP_; }
int Stats::getCurrentHP() const { return currentHP_; }
int Stats::getAttack()    const { return attack_; }
int Stats::getDefense()   const { return defense_; }
int Stats::getSpeed()     const { return speed_; }
int Stats::getMana()      const { return mana_; }
int Stats::getMaxMana()   const { return maxMana_; }

void Stats::setAttack(int value)  { attack_  = value; }
void Stats::setDefense(int value) { defense_ = value; }
void Stats::setSpeed(int value)   { speed_   = value; }
void Stats::setMana(int value)    { mana_    = value; }
void Stats::setMaxHP(int value)   { maxHP_   = value; }
void Stats::setMaxMana(int value) { maxMana_ = value; }

void Stats::takeDamage(int amount) {
    currentHP_ -= amount;
    if (currentHP_ < 0) currentHP_ = 0;
}

void Stats::heal(int amount) {
    currentHP_ += amount;
    if (currentHP_ > maxHP_) currentHP_ = maxHP_;
}

void Stats::spendMana(int amount) {
    mana_ -= amount;
    if (mana_ < 0) mana_ = 0;
}

void Stats::restoreMana(int amount) {
    mana_ += amount;
    if (mana_ > maxMana_) mana_ = maxMana_;
}

bool Stats::isDead() const {
    return currentHP_ <= 0;
}

int Stats::calculateReducedDamage(int rawDamage) const {
    int reduced = rawDamage;
    if (reduced < 1) reduced = 1;
    return reduced;
}

std::ostream& operator<<(std::ostream& os, const Stats& s) {
    os << "HP: "  << s.currentHP_ << "/" << s.maxHP_
       << " | ATK: " << s.attack_
       << " | DEF: " << s.defense_
       << " | SPD: " << s.speed_
       << " | MP: "  << s.mana_ << "/" << s.maxMana_;
    return os;
}
