# Ragnarok RPG — Project Context & Progress

## Project Info

**Course:** Programmation Orientée Objet avec C++
**Licence:** Génie Informatique — Semestre 4
**Academic Year:** 2025–2026
**Deadline:** May 30, 2026
**Current date:** May 18, 2026
**Days remaining:** 12

---

## Academic Requirements

Professor wants to see:
- Encapsulation, Inheritance, Dynamic polymorphism
- Abstract classes, Operator overloading, Friend functions
- Modular architecture, CMake, Git/GitHub workflow

Deliverables:
- README.md, GitHub repo, proper commit history
- Branch-based workflow
- Final report (PDF) + demonstration video

**Advanced challenge:** Implement magic resistance using dynamic polymorphism with NO if/switch on object types. NOT YET DESIGNED — needs attention next session.

**OOP requirements mapping:**
| Requirement | Where it appears |
|---|---|
| Encapsulation | Stats private in Stats class, getters only |
| Inheritance | Warrior/Mage/Archer→Hero→Entity, Poison/Burn/Stun→StatusEffect, Weapon/Armor/Consumable→Item |
| Abstract class | Entity (attack()=0, useSkill()=0), Item (use()=0), StatusEffect (applyEffect()=0) |
| Dynamic polymorphism | Combat calls entity->attack() on any type, no if/switch |
| Operator overload | operator<< on Item ✅, operator<< on Stats ✅ |
| Friend function | friend ostream& operator<< in Item ✅, in Stats ✅ |

---

## Team

| Member | Role | Branch | Status |
|--------|------|--------|--------|
| Soufiane (you) | Leader — UI, Game loop, integration | `feat/soufiane-ui` | Active |
| Anas | Entities — Archer, Enemy, EnemyFactory | `feat/anas` | Archer❌ Enemy❌ EnemyFactory❌ |
| Hamid | Items — fix Inventory display() | `feat/hamid` | display() missing |
| Oussama | Combat — StatusEffect cpps, Combat.cpp | `feat/oussama-statuseffect` | cpps❌ Combat❌ |

---

## Git State (as of May 18)

```
master        ← stable, professor sees this
dev           ← integration branch, managed by Soufiane ← UP TO DATE
feat/soufiane-ui        ← merged into dev ✅
feat/anas               ← Archer/Enemy/EnemyFactory not pushed
feat/hamid              ← Inventory.cpp missing display()
feat/oussama-statuseffect ← StatusEffect/Poison/Burn/Stun cpps not pushed
```

**What is merged into dev:**
- ✅ Stats.h + Stats.cpp
- ✅ Entity.h (fixed, Skill dependency removed) + Entity.cpp
- ✅ Hero.h + Hero.cpp
- ✅ Warrior.h + Warrior.cpp
- ✅ Mage.h + Mage.cpp
- ✅ Inventory.h + Inventory.cpp (missing display())
- ✅ Item, Consumable, Armor
- ✅ Weapon.h + Weapon.cpp (needs const fix)
- ✅ StatusEffect.h, Poison.h, Burn.h, Stun.h
- ✅ Game.h, Game.cpp, main.cpp, ConsoleUI.h, Colors.h

**NOT done yet:**
- ❌ Archer.h/cpp — Anas
- ❌ Enemy.h/cpp — Anas
- ❌ EnemyFactory.h/cpp — Anas
- ❌ StatusEffect.cpp, Poison.cpp, Burn.cpp, Stun.cpp — Oussama
- ❌ Combat.cpp — Oussama (blocked on Anas Enemy)
- ❌ ConsoleUI.cpp — Soufiane
- ❌ selectHeroClass() in Game.cpp — Soufiane (blocked on Anas)
- ❌ gameLoop() in Game.cpp — Soufiane (blocked on Anas + Oussama)

---

## Project Structure

```
rpg-combat-cpp/
├── CMakeLists.txt        ← done
├── .gitignore            ← done
├── README.md
├── claude.md
├── saves/
├── include/
│   ├── Colors.h          ← DONE
│   ├── Game.h            ← DONE
│   ├── ConsoleUI.h       ← DONE (header only)
│   ├── Stats.h           ← DONE
│   ├── Entity.h          ← DONE (Skill dependency removed)
│   ├── Hero.h            ← DONE
│   ├── Warrior.h         ← DONE
│   ├── Mage.h            ← DONE
│   ├── Archer.h          ← Anas TODO
│   ├── Enemy.h           ← Anas TODO
│   ├── EnemyFactory.h    ← Anas TODO
│   ├── Skill.h           ← leave empty dropped
│   ├── Item.h            ← DONE (needs #include <ostream> fix)
│   ├── Weapon.h          ← DONE
│   ├── Armor.h           ← DONE
│   ├── Consumable.h      ← DONE
│   ├── Inventory.h       ← DONE
│   ├── Material.h        ← leave empty dropped
│   ├── Crafting.h        ← leave empty dropped
│   ├── StatusEffect.h    ← Oussama DONE
│   ├── Poison.h          ← Oussama DONE
│   ├── Burn.h            ← Oussama DONE
│   ├── Stun.h            ← Oussama DONE
│   ├── Combat.h          ← DONE (needs Combat.cpp)
│   ├── SaveManager.h     ← leave empty not in scope
│   ├── DataLoader.h      ← leave empty not in scope
│   └── Dungeon.h         ← leave empty not in scope
└── src/
    ├── main.cpp          ← DONE
    ├── Game.cpp          ← PARTIAL (selectHeroClass + gameLoop stubs)
    ├── ConsoleUI.cpp     ← Soufiane TODO
    ├── Stats.cpp         ← DONE
    ├── Entity.cpp        ← DONE
    ├── Hero.cpp          ← DONE
    ├── Warrior.cpp       ← DONE
    ├── Mage.cpp          ← DONE
    ├── Weapon.cpp        ← DONE (needs const fix on 2 methods)
    ├── StatusEffect.cpp  ← Oussama TODO
    ├── Poison.cpp        ← Oussama TODO
    ├── Burn.cpp          ← Oussama TODO
    ├── Stun.cpp          ← Oussama TODO
    ├── Combat.cpp        ← Oussama TODO blocked on Enemy
    └── all others empty
```

**Dropped from scope:** Crafting, Material, Dungeon, SaveManager, DataLoader, Skill.

---

## Full File Status Table

| File | Owner | Status | Notes |
|---|---|---|---|
| `Stats.h` | Anas/Souf | ✅ Done | operator<< added |
| `Stats.cpp` | Souf | ✅ Done | |
| `Entity.h` | Souf | ✅ Done | Skill dependency removed |
| `Entity.cpp` | Souf | ✅ Done | |
| `Hero.h` | Souf | ✅ Done | |
| `Hero.cpp` | Souf | ✅ Done | |
| `Warrior.h` | Souf | ✅ Done | |
| `Warrior.cpp` | Souf | ✅ Done | Stats(120,18,12,8,20) |
| `Mage.h` | Souf | ✅ Done | |
| `Mage.cpp` | Souf | ✅ Done | Stats(70,10,5,12,100) |
| `Archer.h` | Anas | ⏳ TODO | |
| `Archer.cpp` | Anas | ⏳ TODO | Stats(90,14,8,11,40) |
| `Enemy.h` | Anas | ⏳ TODO | |
| `Enemy.cpp` | Anas | ⏳ TODO | |
| `EnemyFactory.h` | Anas | ⏳ TODO | |
| `EnemyFactory.cpp` | Anas | ⏳ TODO | |
| `Item.h` | Hamid | ⚠️ Fix | Add #include <ostream> |
| `Item.cpp` | Hamid | ✅ Done | |
| `Weapon.h` | Souf | ✅ Done | |
| `Weapon.cpp` | Souf | ⚠️ Fix | Add const to getAttackBonus() and getDescription() |
| `Armor.h` | Hamid | ✅ Done | |
| `Armor.cpp` | Hamid | ✅ Done | |
| `Consumable.h` | Hamid | ✅ Done | |
| `Consumable.cpp` | Hamid | ✅ Done | |
| `Inventory.h` | Hamid | ✅ Done | |
| `Inventory.cpp` | Hamid | ⚠️ Fix | Missing display() method |
| `StatusEffect.h` | Oussama | ✅ Done | |
| `StatusEffect.cpp` | Oussama | ⏳ TODO | |
| `Poison.h` | Oussama | ✅ Done | |
| `Poison.cpp` | Oussama | ⏳ TODO | |
| `Burn.h` | Oussama | ✅ Done | |
| `Burn.cpp` | Oussama | ⏳ TODO | |
| `Stun.h` | Oussama | ✅ Done | |
| `Stun.cpp` | Oussama | ⏳ TODO | |
| `Combat.h` | Oussama | ✅ Done | |
| `Combat.cpp` | Oussama | ⏳ TODO | Blocked on Enemy.h |
| `ConsoleUI.h` | Souf | ✅ Done | |
| `ConsoleUI.cpp` | Souf | ⏳ TODO | |
| `Game.h` | Souf | ✅ Done | |
| `Game.cpp` | Souf | ⚠️ Partial | selectHeroClass() + gameLoop() stubs |
| `main.cpp` | Souf | ✅ Done | |
| `CMakeLists.txt` | Souf | ✅ Done | |

---

## Game Design

### Core loop
```
Start → Choose hero class → Enter dungeon → Fight enemy → Loot drop → Next room → Boss fight → Victory / Death
```
5 rooms. Rooms 1-4 spawn random enemies. Room 5 is always Fenrir boss.

### Hero classes
| Class | HP | Mana | ATK | DEF | SPD | Skill |
|---|---|---|---|---|---|---|
| Warrior | 120 | 20 | 18 | 12 | 8 | Berserk — attack twice, costs 10 HP |
| Mage | 70 | 100 | 10 | 5 | 12 | Fireball — 40 dmg, costs 25 mana |
| Archer | 90 | 40 | 14 | 8 | 11 | Precise Shot — ignores DEF, costs 15 mana |

### Enemies
| Enemy | HP | ATK | DEF | SPD | Drop | Drop% | XP |
|---|---|---|---|---|---|---|---|
| Draugr | 40 | 8 | 3 | 6 | Health Potion | 40% | 30 |
| Jotunn | 70 | 14 | 6 | 5 | Iron Sword | 20% | 50 |
| Valkyrie | 55 | 12 | 8 | 15 | Mana Potion | 30% | 45 |
| Fenrir boss | 150 | 22 | 10 | 13 | none | 0% | 200 |

### Items
| Item | Type | Effect |
|---|---|---|
| Health Potion | Consumable | +30 HP |
| Mana Potion | Consumable | +30 mana |
| Iron Sword | Weapon | +5 ATK |
| Leather Armor | Armor | +4 DEF |
| Mjolnir | Weapon | +12 ATK rare |

Inventory: max 5 slots. One weapon + one armor equipped at a time.

### Combat formulas
```
damage     = attacker.attack - defender.defense + random(-2, +2)  min 1
dodge%     = (defender.speed - attacker.speed) * 5%  capped 0-30%
turn order = higher speed goes first. Equal speed = hero goes first.
```

### Status effects
| Effect | Turns | applyEffect() |
|---|---|---|
| Poison | 3 | 5 damage/turn |
| Burn | 3 | 8 damage/turn |
| Stun | 1 | target skips turn |

---

## Specs Per Member

### Anas — pull origin dev first

**Archer** — inherits Hero:
- Constructor: `Hero(name, Stats(90, 14, 8, 11, 40))`
- `getClassName()` returns `"Archer"`
- `attack(target)` — call `Hero::attack(target)`
- `useSkill(target)` — Precise Shot: costs 15 mana, deals `stats_.getAttack()` damage directly NO defense reduction

**Enemy** — inherits Entity:
- Members: `int xpReward_`, `int dropChance_`, `std::string dropItemName_`
- Constructor: `Enemy(name, Stats, xpReward, dropChance, dropItemName)`
- `attack(target)` — same formula as Hero::attack
- `useSkill(target)` — empty
- Getters: `getXPReward()`, `getDropChance()`, `getDropItemName()`

**EnemyFactory** — one static method:
- `static Enemy* createEnemy(const std::string& type)`
- Types: Draugr, Jotunn, Valkyrie, Fenrir (see enemy table above)
- Returns nullptr if unknown type

Push to `feat/anas` only.

### Hamid — pull origin dev first

Add `display()` to `src/Inventory.cpp`:
```cpp
void Inventory::display() const {
    if (items.empty()) { std::cout << "Inventory is empty.\n"; return; }
    for (int i = 0; i < (int)items.size(); i++)
        std::cout << "[" << i << "] " << items[i]->getName() << "\n";
}
```
Add `#include <ostream>` to `include/Item.h`.

Push to `feat/hamid` only.

### Oussama — pull origin dev first

Implement StatusEffect.cpp, Poison.cpp, Burn.cpp, Stun.cpp to match their headers.

**Combat.cpp** (after Anas pushes Enemy):
- `isCombatOver()` — return `!hero.isAlive() || !enemy.isAlive()`
- `startCombat()` — loop while not over: speed check for turn order, call heroTurn() then enemyTurn(), call applyEffects()
- `heroTurn()` — print menu 1=Attack 2=Skill 3=Item, read input, call hero method
- `enemyTurn()` — call `enemy.attack(hero)`
- `applyEffects()` — empty for now

Push to `feat/oussama-statuseffect` only.

---

## Key C++ Concepts Learned

- `.h` = declarations only, `.cpp` = definitions/logic
- `using namespace std` only in `.cpp`, never in `.h`
- Constructor initializer list: `Weapon::Weapon(...) : Item(name, desc, val), attackBonus(attackBonus) {}`
- `unique_ptr<Hero>` — Game owns the hero, auto-deleted when Game dies
- Forward declarations reduce header coupling: `class Hero;`
- `const` on methods = method promises not to modify member variables
- `= default` constructor = let compiler generate it
- `virtual ~Entity() = default` — always on base classes
- `= 0` on a method = pure virtual = class is abstract
- `std::to_string()` — converts int to string for concatenation
- Raw `new` leaks memory — always use `make_unique` instead
- `friend operator<<` — lets the function access private members directly
- `git fetch origin` — updates local snapshot without touching your files
- `git pull origin dev` — sync your branch with latest dev before working
- `git merge feat/soufiane-ui` — merge your work into dev
- When merge conflict: read both sides, keep the correct one, discard the wrong one

---

## Timeline

| Dates | Target |
|---|---|
| May 18–19 | Anas: Archer+Enemy+EnemyFactory. Oussama: StatusEffect cpps + Combat. Souf: ConsoleUI.cpp + fix Weapon.cpp |
| May 20–22 | First full build. Souf: selectHeroClass() + gameLoop() |
| May 23–25 | Full game loop working end to end |
| May 26–28 | Testing, bug fixes, polish. README + final report |
| May 29–30 | Demo video. Merge dev → main. Submit |

---

## Pending Decisions

- **Magic resistance** — professor requirement not yet designed. Must use dynamic polymorphism, zero if/switch.
- **operator<< on Stats** — DONE ✅

---

## Next Conversation Starting Point

Tell Claude:
> "Continue from claude.md.
> Current status:
> - Anas: [what he pushed]
> - Hamid: [what he pushed]
> - Oussama: [what he pushed]
> I want to work on: [ConsoleUI.cpp / gameLoop / integration / debug]"