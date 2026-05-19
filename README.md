# Ragnarok — Norse RPG

## Overview

A turn-based console RPG built in C++ for the OOP course (Licence Génie Informatique — Semestre 4, 2025-2026). The player chooses a hero class, fights through 5 rooms of enemies, and faces Fenrir as the final boss. Built around core OOP principles: inheritance, encapsulation, dynamic polymorphism, abstract classes, operator overloading.

## Features

- 3 hero classes: Warrior, Mage, Archer — each with unique stats and skill
- Turn-based combat with speed-based turn order and dodge system
- XP and leveling system
- Inventory with usable items
- 4 enemy types including Fenrir boss
- Status effects: Poison, Burn, Stun

## Build Instructions

Requires CMake and MinGW.

```bash
git clone https://github.com/S0uf12n8/rpg-combat-cpp.git
cd rpg-combat-cpp
mkdir build && cd build
cmake .. -G "MinGW Makefiles"
cmake --build .
./RagnarokRPG.exe
```

## Class Architecture

```
Entity (abstract)
├── Hero (abstract)
│   ├── Warrior
│   ├── Mage
│   └── Archer
└── Enemy

Item (abstract)
├── Weapon
├── Armor
└── Consumable

StatusEffect (abstract)
├── Poison
├── Burn
└── Stun

Inventory
Combat
Game
EnemyFactory
ConsoleUI
Stats
```

## OOP Requirements

| Requirement          | Implementation                                  |
|----------------------|-------------------------------------------------|
| Encapsulation        | Stats private members, getters only             |
| Inheritance          | Warrior/Mage/Archer → Hero → Entity             |
| Abstract classes     | Entity, Item, StatusEffect                      |
| Dynamic polymorphism | Combat calls attack() on any Entity             |
| Operator overloading | operator<< on Stats and Item                    |
| Friend functions     | friend operator<< in Stats and Item             |

## Team

| Member   | Role                                                              |
|----------|-------------------------------------------------------------------|
| Soufiane | Team Leader — architecture, UI, Game loop, integration           |
| Anas     | Entity system — Stats, Entity, Hero subclasses, Enemy            |
| Hamid    | Item system — Item, Weapon, Armor, Consumable, Inventory         |
| Oussama  | Combat system — StatusEffect, Poison, Burn, Stun, Combat         |

## Branch Strategy

| Branch                      | Purpose                        |
|-----------------------------|--------------------------------|
| master                      | Stable, professor-facing       |
| dev                         | Integration branch             |
| feat/soufiane-ui            | UI and game loop               |
| feat/anas                   | Entity system                  |
| feat/hamid                  | Item system                    |
| feat/oussama-statuseffect   | Combat and status effects      |

## Academic Context

- Course: Programmation Orientée Objet avec C++
- Institution: Faculté Polydisciplinaire
- Year: 2025-2026
