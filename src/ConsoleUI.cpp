#include "ConsoleUI.h"
#include "Hero.h"
#include "Enemy.h"
#include "Item.h"
#include "Colors.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

// ── UTF-8 box-drawing sequences ───────────────────────────────────────────────
static const char* DBL_H  = "\xe2\x95\x90";  // ═
static const char* DBL_V  = "\xe2\x95\x91";  // ║
static const char* DBL_TL = "\xe2\x95\x94";  // ╔
static const char* DBL_TR = "\xe2\x95\x97";  // ╗
static const char* DBL_BL = "\xe2\x95\x9a";  // ╚
static const char* DBL_BR = "\xe2\x95\x9d";  // ╝
static const char* DBL_ML = "\xe2\x95\xa0";  // ╠
static const char* DBL_MR = "\xe2\x95\xa3";  // ╣
static const char* SGL_H  = "\xe2\x94\x80";  // ─
static const char* SGL_V  = "\xe2\x94\x82";  // │
static const char* SGL_TL = "\xe2\x94\x8c";  // ┌
static const char* SGL_TR = "\xe2\x94\x90";  // ┐
static const char* SGL_BL = "\xe2\x94\x94";  // └
static const char* SGL_BR = "\xe2\x94\x98";  // ┘
static const char* BLOCK  = "\xe2\x96\x88";  // █

static string rep(const char* s, int n) {
    string r;
    for (int i = 0; i < n; i++) r += s;
    return r;
}

// Each UTF-8 codepoint counts as 1 display column (valid for narrow Unicode)
static int dispW(const string& s) {
    int w = 0;
    for (size_t i = 0; i < s.size(); ) {
        unsigned char c = (unsigned char)s[i];
        if      (c < 0x80)           { w++; i += 1; }
        else if ((c & 0xE0) == 0xC0) { w++; i += 2; }
        else if ((c & 0xF0) == 0xE0) { w++; i += 3; }
        else                         { w++; i += 4; }
    }
    return w;
}

static string padTo(const string& s, int width) {
    int d = dispW(s);
    return (d >= width) ? s : s + string(width - d, ' ');
}

static string makeBar(int cur, int mx, int len) {
    int f = (mx > 0) ? (cur * len / mx) : 0;
    if (f < 0)   f = 0;
    if (f > len) f = len;
    string b;
    for (int i = 0; i < f;   i++) b += BLOCK;
    for (int i = f; i < len; i++) b += SGL_H;
    return b;
}

// ── private helpers ───────────────────────────────────────────────────────────

void ConsoleUI::clearScreen() const {
    cout << "\033[2J\033[H";
}

void ConsoleUI::showSeparator() const {
    cout << YELLOW << rep(SGL_H, 36) << RESET << "\n";
}

void ConsoleUI::printBox(const string& content) const {
    const int inner = 34;
    cout << DBL_TL << rep(DBL_H, inner) << DBL_TR << "\n";
    cout << DBL_V  << padTo(content, inner) << DBL_V << "\n";
    cout << DBL_BL << rep(DBL_H, inner) << DBL_BR << "\n";
}

void ConsoleUI::printHPBar(const string& label, int cur, int mx) const {
    string bar = makeBar(cur, mx, 14);
    cout << "  " << label << " [" << bar << "] " << cur << "/" << mx << "\n";
}

// ── showTitle ─────────────────────────────────────────────────────────────────

void ConsoleUI::showTitle() const {
#ifdef _WIN32
    system("chcp 65001 > nul");
#endif
    const int inner = 34;
    cout << BOLD << CYAN;
    cout << DBL_TL << rep(DBL_H, inner) << DBL_TR << "\n";
    // ⚡ U+26A1 = \xe2\x9a\xa1
    cout << DBL_V << padTo("   \xe2\x9a\xa1  R A G N A R O K  \xe2\x9a\xa1", inner) << DBL_V << "\n";
    cout << DBL_V << padTo("      A Norse RPG Adventure", inner)                     << DBL_V << "\n";
    cout << DBL_BL << rep(DBL_H, inner) << DBL_BR << "\n";
    cout << RESET;
}

// ── showMainMenu ──────────────────────────────────────────────────────────────

void ConsoleUI::showMainMenu() const {
    const int inner = 34;
    cout << BOLD << CYAN;
    cout << DBL_TL << rep(DBL_H, inner) << DBL_TR << "\n";
    cout << DBL_V << padTo("   \xe2\x9a\xa1  R A G N A R O K  \xe2\x9a\xa1", inner) << DBL_V << "\n";
    cout << DBL_V << padTo("      A Norse RPG Adventure", inner)                     << DBL_V << "\n";
    cout << DBL_BL << rep(DBL_H, inner) << DBL_BR << "\n";
    cout << RESET << "\n";

    cout << "  " << YELLOW << "[1]" << RESET << " New Game\n";
    cout << "  " << YELLOW << "[2]" << RESET << " Load Game\n";
    cout << "  " << YELLOW << "[3]" << RESET << " Exit\n";
    cout << "\n";
    cout << " \033[90m\"The wolf Fenrir awaits...\"\033[0m\n";
}

// ── showHeroSelection ─────────────────────────────────────────────────────────

void ConsoleUI::showHeroSelection() const {
    const int di = 34;  // double-box inner
    const int si = 33;  // single-box inner

    cout << BOLD << CYAN;
    cout << DBL_TL << rep(DBL_H, di) << DBL_TR << "\n";
    cout << DBL_V  << padTo("        Choose Your Class", di) << DBL_V << "\n";
    cout << DBL_BL << rep(DBL_H, di) << DBL_BR << "\n";
    cout << RESET << "\n";

    // — U+2014 = \xe2\x80\x94
    const string EM = "\xe2\x80\x94";

    // Warrior (RED)
    cout << RED;
    cout << " " << SGL_TL << rep(SGL_H, si) << SGL_TR << "\n";
    cout << " " << SGL_V << padTo(" [1] WARRIOR", si)                              << SGL_V << "\n";
    cout << " " << SGL_V << padTo("  HP:120  ATK:18  DEF:12  SPD:8", si)           << SGL_V << "\n";
    cout << " " << SGL_V << padTo("  Skill: Berserk", si)                          << SGL_V << "\n";
    cout << " " << SGL_V << padTo("  Attack twice " + EM + " costs 10 HP", si)     << SGL_V << "\n";
    cout << " " << SGL_BL << rep(SGL_H, si) << SGL_BR << RESET << "\n\n";

    // Mage (CYAN)
    cout << CYAN;
    cout << " " << SGL_TL << rep(SGL_H, si) << SGL_TR << "\n";
    cout << " " << SGL_V << padTo(" [2] MAGE", si)                                 << SGL_V << "\n";
    cout << " " << SGL_V << padTo("  HP:70   ATK:10  DEF:5   SPD:12", si)          << SGL_V << "\n";
    cout << " " << SGL_V << padTo("  Skill: Fireball", si)                         << SGL_V << "\n";
    cout << " " << SGL_V << padTo("  40 dmg " + EM + " costs 25 mana", si)         << SGL_V << "\n";
    cout << " " << SGL_BL << rep(SGL_H, si) << SGL_BR << RESET << "\n\n";

    // Archer (GREEN)
    cout << GREEN;
    cout << " " << SGL_TL << rep(SGL_H, si) << SGL_TR << "\n";
    cout << " " << SGL_V << padTo(" [3] ARCHER", si)                               << SGL_V << "\n";
    cout << " " << SGL_V << padTo("  HP:90   ATK:14  DEF:8   SPD:11", si)          << SGL_V << "\n";
    cout << " " << SGL_V << padTo("  Skill: Precise Shot", si)                     << SGL_V << "\n";
    cout << " " << SGL_V << padTo("  Ignore DEF " + EM + " costs 15 mana", si)     << SGL_V << "\n";
    cout << " " << SGL_BL << rep(SGL_H, si) << SGL_BR << RESET << "\n\n";
}

// ── showHeroStats ─────────────────────────────────────────────────────────────

void ConsoleUI::showHeroStats(const Hero& hero) const {
    const int inner = 34;
    const int BAR   = 14;

    string info   = "  " + hero.getName() + " (" + hero.getClassName() + ")"
                  + "  Lv." + to_string(hero.getLevel());
    string hpLine = "  HP  [" + makeBar(hero.getStats().getCurrentHP(), hero.getStats().getMaxHP(), BAR)
                  + "] " + to_string(hero.getStats().getCurrentHP()) + "/" + to_string(hero.getStats().getMaxHP());
    string mpLine = "  MP  [" + makeBar(hero.getStats().getMana(), hero.getStats().getMaxMana(), BAR)
                  + "] " + to_string(hero.getStats().getMana()) + "/" + to_string(hero.getStats().getMaxMana());

    cout << CYAN;
    cout << DBL_TL << rep(DBL_H, inner) << DBL_TR << "\n";
    cout << DBL_V  << padTo(info,   inner) << DBL_V << "\n";
    cout << DBL_V  << padTo(hpLine, inner) << DBL_V << "\n";
    cout << DBL_V  << padTo(mpLine, inner) << DBL_V << "\n";
    cout << DBL_BL << rep(DBL_H, inner) << DBL_BR << "\n";
    cout << RESET;
}

// ── showCombatStart ───────────────────────────────────────────────────────────

void ConsoleUI::showCombatStart(const string& enemyName) const {
    const int inner = 32;
    const string DARK = "\033[90m";

    if (enemyName == "Draugr") {
        cout << WHITE;
        cout << "  " << DBL_TL << rep(DBL_H, inner) << DBL_TR << "\n";
        cout << "  " << DBL_V  << padTo("   \xe2\x98\xa0  A DRAUGR APPROACHES  \xe2\x98\xa0   ", inner) << DBL_V << "\n";
        cout << "  " << DBL_BL << rep(DBL_H, inner) << DBL_BR << "\n";
        cout << RESET;
        cout << "\n";
        cout << "     .-.\n";
        cout << "    (o o)\n";
        cout << "    | O |\n";
        cout << "   /|---|\\  \n";
        cout << "  / |   | \\\n";
        cout << "     | |\n";
        cout << "    _| |_\n";
        cout << "\n";
        cout << DARK << "  \"The undead stirs from its grave...\"\n" << RESET;

    } else if (enemyName == "Jotunn") {
        cout << YELLOW;
        cout << "  " << DBL_TL << rep(DBL_H, inner) << DBL_TR << "\n";
        cout << "  " << DBL_V  << padTo("   \xe2\x9b\xb0  A JOTUNN RISES  \xe2\x9b\xb0", inner) << DBL_V << "\n";
        cout << "  " << DBL_BL << rep(DBL_H, inner) << DBL_BR << "\n";
        cout << RESET;
        cout << "\n";
        cout << "     \\O/\n";
        cout << "      |\n";
        cout << "     /|\\\n";
        cout << "     / \\\n";
        cout << "\n";
        cout << DARK << "  \"The ground trembles beneath its feet...\"\n" << RESET;

    } else if (enemyName == "Valkyrie") {
        cout << CYAN;
        cout << "  " << DBL_TL << rep(DBL_H, inner) << DBL_TR << "\n";
        cout << "  " << DBL_V  << padTo("   \xe2\x9a\xa1  A VALKYRIE DESCENDS  \xe2\x9a\xa1  ", inner) << DBL_V << "\n";
        cout << "  " << DBL_BL << rep(DBL_H, inner) << DBL_BR << "\n";
        cout << RESET;
        cout << "\n";
        cout << "     }|{\n";
        cout << "    _\\|/_\n";
        cout << "   ( o o )\n";
        cout << "    \\___/\n";
        cout << "\n";
        cout << DARK << "  \"She rides from Asgard to claim the fallen...\"\n" << RESET;

    } else if (enemyName == "Fenrir") {
        cout << BOLD << RED;
        cout << "  " << DBL_TL << rep(DBL_H, inner) << DBL_TR << "\n";
        cout << "  " << DBL_V  << padTo("  \xf0\x9f\x90\xba  FENRIR \xe2\x80\x94 THE GREAT WOLF", inner) << DBL_V << "\n";
        cout << "  " << DBL_BL << rep(DBL_H, inner) << DBL_BR << "\n";
        cout << RESET;
        cout << "\n";
        cout << "    /\\_____/\\\n";
        cout << "   /  o   o  \\\n";
        cout << "  ( ==  ^  == )\n";
        cout << "   )         (\n";
        cout << "  (           )\n";
        cout << "\n";
        cout << DARK << "  \"The wolf that will devour the sun...\"\n" << RESET;

    } else {
        cout << RED;
        cout << "  " << DBL_TL << rep(DBL_H, inner) << DBL_TR << "\n";
        cout << "  " << DBL_V  << padTo("  A " + enemyName + " appears!", inner) << DBL_V << "\n";
        cout << "  " << DBL_BL << rep(DBL_H, inner) << DBL_BR << "\n";
        cout << RESET;
    }

    cout << "\n";
}

// ── showCombatMenu ────────────────────────────────────────────────────────────

void ConsoleUI::showCombatMenu() const {
    const int si = 33;
    cout << " " << SGL_TL << rep(SGL_H, si) << SGL_TR << "\n";
    cout << " " << SGL_V  << padTo(" [1] Attack      [2] Use Skill", si) << SGL_V << "\n";
    cout << " " << SGL_V  << padTo(" [3] Use Item    [4] Run",       si) << SGL_V << "\n";
    cout << " " << SGL_BL << rep(SGL_H, si) << SGL_BR << "\n";
}

// ── showCombatLog ─────────────────────────────────────────────────────────────

void ConsoleUI::showCombatLog(const string& message) const {
    // » U+00BB = \xc2\xbb
    cout << "\n" << YELLOW << " \xc2\xbb " << RESET << message << "\n";
}

// ── showEnemyStats ────────────────────────────────────────────────────────────

void ConsoleUI::showEnemyStats(const Enemy& enemy) const {
    cout << RED << "  " << enemy.getName() << RESET << "\n";
    printHPBar("HP ", enemy.getStats().getCurrentHP(), enemy.getStats().getMaxHP());
}

// ── showHPBars ────────────────────────────────────────────────────────────────

void ConsoleUI::showHPBars(const Hero& hero, const Enemy& enemy) const {
    const int inner = 34;
    const int BAR   = 14;

    auto barLine = [&](const string& label, int cur, int mx) -> string {
        return "  " + label + "  [" + makeBar(cur, mx, BAR)
             + "] " + to_string(cur) + "/" + to_string(mx);
    };

    cout << CYAN;
    cout << DBL_TL << rep(DBL_H, inner) << DBL_TR << "\n";

    string heroInfo = "  " + hero.getName() + " (" + hero.getClassName() + ")"
                    + "      Lv." + to_string(hero.getLevel());
    cout << DBL_V << padTo(heroInfo, inner) << DBL_V << "\n";
    cout << DBL_V << padTo(barLine("HP", hero.getStats().getCurrentHP(), hero.getStats().getMaxHP()), inner) << DBL_V << "\n";
    cout << DBL_V << padTo(barLine("MP", hero.getStats().getMana(),      hero.getStats().getMaxMana()), inner) << DBL_V << "\n";

    cout << DBL_ML << rep(DBL_H, inner) << DBL_MR << "\n";
    cout << RESET  << RED;

    cout << DBL_V << padTo("  " + enemy.getName(), inner) << DBL_V << "\n";
    cout << DBL_V << padTo(barLine("HP", enemy.getStats().getCurrentHP(), enemy.getStats().getMaxHP()), inner) << DBL_V << "\n";

    cout << DBL_BL << rep(DBL_H, inner) << DBL_BR << "\n";
    cout << RESET;
}

// ── showInventory ─────────────────────────────────────────────────────────────

void ConsoleUI::showInventory(const vector<Item*>& items) const {
    showSeparator();
    if (items.empty()) {
        cout << "  Inventory is empty.\n";
    } else {
        for (int i = 0; i < (int)items.size(); i++)
            cout << "  [" << i << "] " << items[i]->getName() << "\n";
    }
    showSeparator();
}

void ConsoleUI::showItemFound(const string& itemName) const {
    cout << GREEN << "  Found: " << itemName << "!" << RESET << "\n";
}

// ── showLevelUp ───────────────────────────────────────────────────────────────

void ConsoleUI::showLevelUp(int newLevel) const {
    cout << BOLD << YELLOW
         << "  LEVEL UP! You are now level " << newLevel << "!"
         << RESET << "\n";
}

// ── showDeathScreen ───────────────────────────────────────────────────────────

void ConsoleUI::showDeathScreen() const {
    const int inner = 34;
    cout << RED;
    cout << DBL_TL << rep(DBL_H, inner) << DBL_TR << "\n";
    cout << DBL_V  << padTo("          YOU HAVE FALLEN", inner) << DBL_V << "\n";
    cout << DBL_BL << rep(DBL_H, inner) << DBL_BR << "\n";
    cout << " Odin does not welcome cowards.\n";
    cout << RESET;
}

// ── showVictory ───────────────────────────────────────────────────────────────

void ConsoleUI::showVictory() const {
    const int inner = 34;
    cout << BOLD << GREEN;
    cout << DBL_TL << rep(DBL_H, inner) << DBL_TR << "\n";
    cout << DBL_V  << padTo("            VICTORY!", inner)                  << DBL_V << "\n";
    cout << DBL_V  << padTo("  Your legend echoes in Valhalla!", inner)     << DBL_V << "\n";
    cout << DBL_BL << rep(DBL_H, inner) << DBL_BR << "\n";
    cout << RESET;
}

// ── showMessage ───────────────────────────────────────────────────────────────

void ConsoleUI::showMessage(const string& msg) const {
    cout << "  " << msg << "\n";
}
