📖 Overview
RPG Combat Console is a semester project developed as part of the C++ Object-Oriented Programming course (Licence MIP — Semester 4). The game opposes a player-controlled hero against randomly generated enemies in a turn-based combat system, built entirely around OOP principles: inheritance, encapsulation, and dynamic polymorphism.

✨ Features

🧙 Hero creation — choose your name and class (Warrior, Mage, Archer)
📊 Stats system — HP, attack, defense, speed per class
⚡ Class-specific skills — unique abilities per hero type
🔄 Turn-based combat — damage calculation, death handling, enemy AI
🎯 XP & leveling — gain experience and evolve your character
🎒 Inventory system — consumable items with real effect during combat
🔮 Advanced magic system — resistance-based damage using dynamic polymorphism (no if/switch on type)


🏗️ Project Structure
```text
rpg-combat-cpp/
├── include/
│   ├── Character.h
│   ├── Hero.h
│   ├── Enemy.h
│   ├── Warrior.h
│   ├── Mage.h
│   ├── Archer.h
│   ├── Skill.h
│   ├── Item.h
│   ├── Inventory.h
│   ├── Combat.h
│   └── Game.h
├── src/
│   ├── Character.cpp
│   ├── Hero.cpp
│   ├── Enemy.cpp
│   ├── Warrior.cpp
│   ├── Mage.cpp
│   ├── Archer.cpp
│   ├── Skill.cpp
│   ├── Item.cpp
│   ├── Inventory.cpp
│   ├── Combat.cpp
│   ├── Game.cpp
│   └── main.cpp
├── docs/
│   ├── class_diagram.png
│   └── rapport.pdf
├── Makefile
├── .gitignore
└── README.md
```
🚀 Getting Started
Prerequisites

g++ with C++17 support
make

bash# Check your compiler
g++ --version
Build & Run
bash# Clone the repository
git clone https://github.com/YOUR_USERNAME/rpg-combat-cpp.git
cd rpg-combat-cpp

# Compile
make

# Run
./rpg
Clean build
bashmake clean

🧱 Class Architecture
```text
Character  (abstract base)
├── Hero
│   ├── Warrior
│   ├── Mage
│   └── Archer
└── Enemy

Inventory  ───  Item
Combat     ───  Hero + Enemy
Game       ───  Combat + Inventory
```
The magic system is implemented via virtual methods (computeDamage(), applyResistance()), eliminating all type-based conditionals — fully polymorphic by design.

👥 Team
MemberRoleScope Soufiane Team LeaderGame loop, architecture, Game.cpp, main.cpp
Anas Character SystemCharacter, Hero, Warrior, Mage, Archer
Hamide Combat EngineEnemy, Combat — turn logic, damage, AI
Oussama Items & ProgressionItem, Inventory, Skill, XP system

🌿 Branch Strategy
BranchPurposemasterStable, reviewed code onlydevIntegration — all features merge here firstfeature/heroMember 2's working branchfeature/combatMember 3's working branchfeature/inventoryMember 4's working branch

Rule: No direct pushes to master. All changes go through dev via Pull Request.


📚 Academic Context

Course: Programmation Orientée Objet — C++
Level: Licence Génie Informatique (MIP) — Semestre 4
Institution: FPT
Academic Year: 2025–2026


📄 License
This project is developed for academic purposes only. Not intended for commercial use.
