#pragma once
#include <string>
#include <vector>

// Forward declarations — no includes needed until ConsoleUI.cpp
class Hero;
class Enemy;
class Item;

class ConsoleUI {
public:
    ConsoleUI() = default;

    
    void showTitle() const;
    void showMainMenu() const;
    void clearScreen() const;
    void showSeparator() const;

    
    void showHeroStats(const Hero& hero) const;
    void showHeroSelection() const;         
    
    void showCombatStart(const std::string& enemyName) const;
    void showCombatMenu() const;
    void showCombatLog(const std::string& message) const;
    void showEnemyStats(const Enemy& enemy) const;
    void showHPBars(const Hero& hero, const Enemy& enemy) const;

    
    void showInventory(const std::vector<Item*>& items) const;
    void showItemFound(const std::string& itemName) const;

    
    void showLevelUp(int newLevel) const;
    void showDeathScreen() const;
    void showVictory() const;
    void showMessage(const std::string& msg) const;   

private:
    void printBox(const std::string& content) const;  
    void printHPBar(const std::string& label, int current, int max) const;
};