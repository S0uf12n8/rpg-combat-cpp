#ifndef STATS_H
#define STATS_H
#include <ostream>

class Stats {
private:
    int maxHP_;
    int currentHP_;
    int attack_;
    int defense_;
    int speed_;
    int mana_;
    int maxMana_;
public:
    Stats(int maxHP, int attack, int defense, int speed, int mana = 0);
    int getMaxHP()     const;
    int getCurrentHP() const;
    int getAttack()    const;
    int getDefense()   const;
    int getSpeed()     const;
    int getMana()      const;
    int getMaxMana()   const;
    void setAttack(int value);
    void setDefense(int value);
    void setSpeed(int value);
    void setMana(int value);
    void setMaxHP(int value);
    void setMaxMana(int value);
    void takeDamage(int amount);
    void heal(int amount);
    void spendMana(int amount);
    void restoreMana(int amount);
    bool isDead() const;
    int calculateReducedDamage(int rawDamage) const;

    friend std::ostream& operator<<(std::ostream& os, const Stats& s);
};

#endif