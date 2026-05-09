# RPG Combat Console

## 📖 Overview

RPG Combat Console is a semester project developed as part of the **C++ Object-Oriented Programming course** (Licence MIP — Semester 4).

The game features a player-controlled hero fighting randomly generated enemies in a **turn-based combat system**, built around core OOP principles:

* Inheritance
* Encapsulation
* Dynamic polymorphism

---

## ✨ Features

* 🧙 **Hero creation** — choose name and class (Warrior, Mage, Archer)
* 📊 **Stats system** — HP, attack, defense, speed per class
* ⚡ **Class-specific skills** — unique abilities per hero
* 🔄 **Turn-based combat** — damage calculation, enemy AI
* 🎯 **XP & leveling** — character progression
* 🎒 **Inventory system** — usable items during combat
* 🔮 **Advanced magic system** — resistance-based damage using polymorphism *(no if/switch on type)*

---

## 🏗️ Project Structure

```bash
rpg-combat-cpp/
D:.
│   .gitignore
│   claud.md
│   CMakeLists.txt
│   README.md
│
├───.vscode
│       c_cpp_properties.json
│       launch.json
│       settings.json
│
├───assets
│   └───ascii_art
├───build
├───docs
├───external
├───include
│   │   Archer.h
│   │   Armor.h
│   │   Burn.h
│   │   Colors.h
│   │   Combat.h
│   │   ConsoleUI.h
│   │   Consumable.h
│   │   Crafting.h
│   │   DataLoader.h
│   │   Dungeon.h
│   │   Enemy.h
│   │   EnemyFactory.h
│   │   Entity.h
│   │   Game.h
│   │   Hero.h
│   │   Inventory.h
│   │   Item.h
│   │   Mage.h
│   │   Material.h
│   │   Poison.h
│   │   SaveManager.h
│   │   Skill.h
│   │   Stats.h
│   │   StatusEffect.h
│   │   Stun.h
│   │   Warrior.h
│   │   Weapon.h
│   │
│   └───combat
│           Combat.h
│
├───saves
│       .gitkeep
│
└───src
        Archer.cpp
        Archer.h
        Armor.cpp
        Burn.cpp
        Combat.cpp
        Combat.h
        ConsoleUI.cpp
        Consumable.cpp
        Crafting.cpp
        DataLoader.cpp
        Dungeon.cpp
        Enemy.cpp
        EnemyFactory.cpp
        Entity.cpp
        Entity.h
        Game.cpp
        Hero.cpp
        Inventory.cpp
        Item.cpp
        Mage.cpp
        Mage.h
        main.cpp
        Material.cpp
        Poison.cpp
        SaveManager.cpp
        Skill.cpp
        Stats.cpp
        StatusEffect.cpp
        Stun.cpp
        Warrior.cpp
        Warrior.h
        Weapon.cpp


```

---

## 🚀 Getting Started

### Prerequisites

* `g++` with C++17 support
* `make`

Check your compiler:

```bash
g++ --version
```

### Build & Run

```bash
git clone https://github.com/YOUR_USERNAME/rpg-combat-cpp.git
cd rpg-combat-cpp

make
./rpg
```

### Clean build

```bash
make clean
```

---

## 🧱 Class Architecture

```
Character (abstract)
├── Hero
│   ├── Warrior
│   ├── Mage
│   └── Archer
└── Enemy

Inventory ─── Item  
Combat ─── Hero + Enemy  
Game ─── Combat + Inventory  
```

The magic system is implemented using **virtual methods** (`computeDamage`, `applyResistance`), ensuring a fully polymorphic design without type-based conditionals.

---

## 👥 Team

| Member   | Role                | Responsibilities                                |
| -------- | ------------------- | ----------------------------------------------- |
| Soufiane | Team Leader         | Game loop, architecture, `Game.cpp`, `main.cpp` |
| Anas     | Character System    | Character, Hero, Warrior, Mage, Archer          |
| Hamid    | Combat Engine       | Enemy, Combat (logic, AI, damage)               |
| Oussama  | Items & Progression | Item, Inventory, Skill, XP system               |

---

## 🌿 Branch Strategy

| Branch              | Purpose                    |
| ------------------- | -------------------------- |
| `master`            | Stable, reviewed code only |
| `dev`               | Integration branch         |
| `feature/hero`      | Character system           |
| `feature/combat`    | Combat system              |
| `feature/inventory` | Items system               |

**Rule:** No direct pushes to `master`. All changes go through `dev` via Pull Requests.

---

## 📚 Academic Context

* Course: Programmation Orientée Objet — C++
* Level: Licence Génie Informatique (MIP) — Semestre 4
* Institution: FPT
* Academic Year: 2025–2026

---

## 📄 License

This project is developed for academic purposes only. Not intended for commercial use.
