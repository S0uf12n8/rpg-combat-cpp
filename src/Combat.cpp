#include "Combat.h"
#include "Hero.h"
#include "Entity.h"
#include "Inventory.h"
#include "Item.h"
#include <iostream>
#include <cstdlib>

using namespace std;

Combat::Combat(Hero& hero, Entity& enemy)
    : hero(hero), enemy(enemy), maxRounds(50)
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
    cout << "\n[1] Attack  [2] Use Skill  [3] Use Item  [4] Run\n> ";
    int choice;
    cin >> choice;

    if (choice == 1) {
        if (tryDodge(hero, enemy)) {
            cout << enemy.getName() << " dodges the attack!\n";
        } else {
            int dmg = calculateDamage(hero, enemy);
            enemy.takeDamage(dmg);
            cout << hero.getName() << " attacks for " << dmg << " damage!\n";
        }
    } else if (choice == 2) {
        hero.useSkill(enemy);
    } else if (choice == 3) {
        Inventory& inv = hero.getInventory();
        if (inv.getSize() == 0) {
            cout << "No items in inventory.\n";
        } else {
            inv.display();
            cout << "Choose item index: ";
            int idx;
            cin >> idx;
            inv.useItem(idx);
        }
    } else if (choice == 4) {
        if (rand() % 2 == 0) {
            cout << hero.getName() << " escaped!\n";
            maxRounds = 0;
        } else {
            cout << "Failed to escape!\n";
        }
    } else {
        cout << "Invalid choice.\n";
    }
}

void Combat::enemyTurn() {
    if (tryDodge(enemy, hero)) {
        cout << hero.getName() << " dodges the attack!\n";
    } else {
        int dmg = calculateDamage(enemy, hero);
        hero.takeDamage(dmg);
        cout << enemy.getName() << " attacks for " << dmg << " damage!\n";
    }
}

void Combat::startCombat() {
    cout << "=== COMBAT START ===\n";
    int round = 0;

    while (!isCombatOver() && round < maxRounds) {
        round++;
        cout << "\n--- Round " << round << " ---\n";
        cout << hero.getName()  << " HP: " << hero.getStats().getCurrentHP()
             << "/" << hero.getStats().getMaxHP() << "\n";
        cout << enemy.getName() << " HP: " << enemy.getStats().getCurrentHP()
             << "/" << enemy.getStats().getMaxHP() << "\n";

        applyEffects();

        if (hero.getStats().getSpeed() >= enemy.getStats().getSpeed()) {
            heroTurn();
            if (isCombatOver() || maxRounds == 0) break;
            enemyTurn();
        } else {
            enemyTurn();
            if (!isCombatOver()) heroTurn();
        }
    }

    if (!enemy.isAlive()) {
        cout << "\n" << enemy.getName() << " is defeated!\n";
    } else if (!hero.isAlive()) {
        cout << "\n" << hero.getName() << " has fallen!\n";
    }
}
