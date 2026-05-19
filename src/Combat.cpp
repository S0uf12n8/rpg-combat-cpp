#include "Combat.h"
#include "Entity.h"
#include"Hero.h"
#include"Enemy.h"
#include <iostream>
#include <cstdlib> 

Combat::Combat(Hero& hero, Enemy& enemy):hero(hero), enemy(enemy),heroStunned(false),enemyStunned(false){}

Combat::~Combat(){
    cleanupEffects(heroEffects);
    cleanupEffects(enemyEffects);
}

void Combat::cleanupEffects(std::vector<StatusEffect*>& effects){
    for (StatusEffect* e : effects)
        delete e;
    effects.clear();
}

int Combat::calculateDamage(Entity& attacker, Entity& defender){
    int damage = attacker.getStats().getAttack()-defender.getStats().getDefense();
    damage += (rand()%5)-2;
    if (damage<1)damage=1;
    return damage;
}

bool Combat::tryDodge(Entity& attacker, Entity& defender){
    int dodgeChance = (defender.getStats().getSpeed()-attacker.getStats().getSpeed())*5;
    if (dodgeChance<0) dodgeChance=0;
    if (dodgeChance>30) dodgeChance=30;
    return (rand()%100)<dodgeChance;
}

void Combat::applyEffects(Entity& target, std::vector<StatusEffect*>& effects,bool& stunned){
    for (StatusEffect* e : effects){
        e->applyEffect(target);
        if (e->getName()=="Stun") stunned=true;
        e->tick();
    }
    cleanupEffects(effects);
}

bool Combat::playerWon() const {
    return !enemy.isAlive();
}

void Combat::start(){
    std::cout << "************  COMBAT START  ************\n";
    while (hero.isAlive()&& enemy.isAlive()){
        applyEffects(hero, heroEffects, heroStunned);
        applyEffects(enemy, enemyEffects, enemyStunned);

        if(!hero.isAlive()){std::cout<<hero.getName()<<" has fallen!\n"; break;}
        if(!enemy.isAlive()){std::cout<<enemy.getName()<<" defeated!\n"; break;}
        if (heroStunned){
            std::cout<<hero.getName() << " is stunned and skips their turn!\n";
            heroStunned = false;
        }else{
            std::cout<< "\n[1] Attack  [2] Skill  [3] Item  [4] Run\n> ";
            int choice; std::cin>>choice;
            if(choice==1){
                if(tryDodge(hero,enemy))
                    std::cout<<enemy.getName()<<" dodges the attack!\n";
                else{
                    int dmg = calculateDamage(hero, enemy);
                    enemy.takeDamage(dmg);
                    std::cout<<hero.getName()<< " attacks for " << dmg << " damage!\n";
                }

            }else if (choice==2){
                hero.useSkill(enemy);
            }else if (choice==4){
                if (rand()%2==0){std::cout<<"Escaped!\n"; return;}
                else std::cout<<"Failed to escape!\n";
            }
        }
        if(!enemy.isAlive()){std::cout<<enemy.getName()<<" defeated!\n"; break;}
        if (enemyStunned){
            std::cout<<enemy.getName()<< " is stunned and skips their turn!\n";
            enemyStunned=false;
        }else{
            if (tryDodge(enemy,hero))
                std::cout<<"You dodge the attack!\n";
            else{
                int dmg = calculateDamage(enemy,hero);
                hero.takeDamage(dmg);
                std::cout<<enemy.getName()<<" attacks for "<<dmg<<" damage!\n";
            }
        }
        if (!hero.isAlive()){std:: cout<<hero.getName()<<" has fallen!\n"; break;}
    }
    
}