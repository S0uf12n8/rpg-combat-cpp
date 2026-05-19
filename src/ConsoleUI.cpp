#include "ConsoleUI.h"
#include "Hero.h"
#include "Enemy.h"
#include "Item.h"
#include "Colors.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void ConsoleUI::clearScreen() const {
    cout << "\033[2J\033[H";
}

void ConsoleUI::showSeparator() const {
    cout << YELLOW << string(50, '=') << RESET << "\n";
}

void ConsoleUI::printBox(const string& content) const {
    const int width = 40;
    string border(width, '*');
    cout << border << "\n";

    int padding = (width - 2 - (int)content.size()) / 2;
    if (padding < 0) padding = 0;

    cout << "*" << string(padding, ' ') << content
         << string(width - 2 - padding - (int)content.size(), ' ') << "*\n";

    cout << border << "\n";
}

void ConsoleUI::printHPBar(const string& label, int current, int max) const {
    const int barLen = 20;
    int filled = (max > 0) ? (current * barLen / max) : 0;
    if (filled > barLen) filled = barLen;
    if (filled < 0)      filled = 0;

    string bar(filled, '#');
    bar += string(barLen - filled, '-');

    cout << label << " [" << bar << "] " << current << "/" << max << "\n";
}

void ConsoleUI::showTitle() const {
    cout << BOLD << CYAN;
    printBox("RAGNAROK");
    printBox("A Norse RPG");
    cout << RESET;
}

void ConsoleUI::showMainMenu() const {
    showSeparator();
    cout << "1. New Game\n";
    cout << "2. Quit\n";
    showSeparator();
}

void ConsoleUI::showHeroSelection() const {
    showSeparator();
    cout << BOLD << "Choose your hero:\n" << RESET;
    cout << "\n";
    cout << "1. " << CYAN << "Warrior" << RESET
         << "  HP:120 ATK:18 DEF:12 SPD:8\n"
         << "   Berserk: attack twice, costs 10 HP\n\n";
    cout << "2. " << CYAN << "Mage" << RESET
         << "     HP:70  ATK:10 DEF:5  SPD:12\n"
         << "   Fireball: 40 dmg, costs 25 mana\n\n";
    cout << "3. " << CYAN << "Archer" << RESET
         << "   HP:90  ATK:14 DEF:8  SPD:11\n"
         << "   Precise Shot: ignore DEF, costs 15 mana\n\n";
    showSeparator();
}

void ConsoleUI::showHeroStats(const Hero& hero) const {
    showSeparator();
    cout << BOLD << hero.getName() << RESET
         << "  Class: " << hero.getClassName()
         << "  Level: " << hero.getLevel() << "\n";
    printHPBar("HP  ", hero.getStats().getCurrentHP(), hero.getStats().getMaxHP());
    printHPBar("MP  ", hero.getStats().getMana(),      hero.getStats().getMaxMana());
    showSeparator();
}

void ConsoleUI::showCombatStart(const string& enemyName) const {
    cout << RED << "A " << enemyName << " appears!" << RESET << "\n";
}

void ConsoleUI::showCombatMenu() const {
    cout << "1. Attack\n";
    cout << "2. Use Skill\n";
    cout << "3. Use Item\n";
    cout << "4. Run\n";
}

void ConsoleUI::showCombatLog(const string& message) const {
    cout << YELLOW << message << RESET << "\n";
}

void ConsoleUI::showEnemyStats(const Enemy& enemy) const {
    cout << RED << enemy.getName() << RESET << "\n";
    printHPBar("HP  ", enemy.getStats().getCurrentHP(), enemy.getStats().getMaxHP());
}

void ConsoleUI::showHPBars(const Hero& hero, const Enemy& enemy) const {
    printHPBar(hero.getName(),  hero.getStats().getCurrentHP(),  hero.getStats().getMaxHP());
    printHPBar(enemy.getName(), enemy.getStats().getCurrentHP(), enemy.getStats().getMaxHP());
}

void ConsoleUI::showInventory(const vector<Item*>& items) const {
    showSeparator();
    if (items.empty()) {
        cout << "Inventory is empty.\n";
    } else {
        for (int i = 0; i < (int)items.size(); i++) {
            cout << "[" << i << "] " << items[i]->getName() << "\n";
        }
    }
    showSeparator();
}

void ConsoleUI::showItemFound(const string& itemName) const {
    cout << GREEN << "You found: " << itemName << "!" << RESET << "\n";
}

void ConsoleUI::showLevelUp(int newLevel) const {
    cout << BOLD << YELLOW
         << "LEVEL UP! You are now level " << newLevel << "!"
         << RESET << "\n";
}

void ConsoleUI::showDeathScreen() const {
    cout << RED;
    printBox("YOU DIED");
    cout << RESET;
    cout << "Odin does not welcome cowards.\n";
}

void ConsoleUI::showVictory() const {
    cout << BOLD << GREEN;
    printBox("VICTORY!");
    cout << RESET;
    cout << "Your legend will be sung in Valhalla!\n";
}

void ConsoleUI::showMessage(const string& msg) const {
    cout << msg << "\n";
}
