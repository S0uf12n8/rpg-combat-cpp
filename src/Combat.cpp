#include "Combat.h"
#include "Hero.h"
#include "Enemy.h"
#include "Entity.h"
#include "Inventory.h"
#include "Item.h"
#include "Consumable.h"
#include "Weapon.h"
#include "Armor.h"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

Combat::Combat(Hero& hero, Entity& enemy)
    : hero(hero), enemy(enemy), maxRounds(50), escaped_(false)
{
}

int Combat::calculateDamage(Entity& attacker, Entity& defender) {
    int damage = attacker.getStats().getAttack() - defender.getStats().getDefense();
    damage += (rand() % 5) - 2;
    if (damage < 1) damage = 1;
    return damage;
}

bool Combat::tryDodge(Entity& attacker, Entity& defender) {
    int dodgeChance = (defender.getStats().getSpeed() - attacker.getStats().getSpeed()) * 5;
    if (dodgeChance < 0)  dodgeChance = 0;
    if (dodgeChance > 30) dodgeChance = 30;
    return (rand() % 100) < dodgeChance;
}

bool Combat::isCombatOver() {
    return !hero.isAlive() || !enemy.isAlive();
}

void Combat::applyEffects() {
}

void Combat::heroTurn() {
    ui.showCombatMenu();
    cout << " > ";
    int choice;
    cin >> choice;

    if (choice == 1) {
        if (tryDodge(hero, enemy)) {
            ui.showCombatLog(enemy.getName() + " dodges the attack!");
        } else {
            int dmg = calculateDamage(hero, enemy);
            enemy.takeDamage(dmg);
            ui.showCombatLog(hero.getName() + " attacks for " + to_string(dmg) + " damage!");
        }
    } else if (choice == 2) {
        hero.useSkill(enemy);
    } else if (choice == 3) {
        Inventory& inv = hero.getInventory();
        if (inv.getSize() == 0) {
            ui.showCombatLog("No items in inventory.");
        } else {
            inv.display();
            ui.showCombatLog("Choose item index:");
            int idx;
            cin >> idx;

            Item* item = inv.getItem(idx);
            if (item) {
                if (Consumable* c = dynamic_cast<Consumable*>(item)) {
                    if (c->getName().find("Mana") != std::string::npos) {
                        hero.getStats().restoreMana(c->getHealAmount());
                    } else {
                        hero.getStats().heal(c->getHealAmount());
                    }
                } else if (Weapon* w = dynamic_cast<Weapon*>(item)) {
                    hero.equipWeapon(w);
                } else if (Armor* a = dynamic_cast<Armor*>(item)) {
                    hero.equipArmor(a);
                }
            }
            inv.useItem(idx);
        }
    } else if (choice == 4) {
        if (rand() % 2 == 0) {
            ui.showCombatLog(hero.getName() + " escaped!");
            escaped_ = true;
        } else {
            ui.showCombatLog("Failed to escape!");
        }
    } else {
        ui.showCombatLog("Invalid choice.");
    }
}

void Combat::enemyTurn() {
    if (tryDodge(enemy, hero)) {
        ui.showCombatLog(hero.getName() + " dodges the attack!");
    } else {
        int dmg = calculateDamage(enemy, hero);
        hero.takeDamage(dmg);
        ui.showCombatLog(enemy.getName() + " attacks for " + to_string(dmg) + " damage!");
    }
}

void Combat::startCombat() {
    ui.showSeparator();
    int round = 0;

    while (!isCombatOver() && round < maxRounds) {
        round++;
        ui.showSeparator();
        ui.showCombatLog("Round " + to_string(round));
        ui.showHPBars(hero, dynamic_cast<Enemy&>(enemy));

        applyEffects();

        if (hero.getStats().getSpeed() >= enemy.getStats().getSpeed()) {
            heroTurn();
            if (isCombatOver() || escaped_) break;
            enemyTurn();
        } else {
            enemyTurn();
            if (!isCombatOver()) heroTurn();
        }
    }

    if (!enemy.isAlive()) {
        ui.showCombatLog(enemy.getName() + " is defeated!");
    } else if (!hero.isAlive()) {
        ui.showCombatLog(hero.getName() + " has fallen!");
    }
}
