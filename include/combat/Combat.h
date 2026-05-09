#pragma once
#include "Warrior.h"
#include "Mage.h"
#include "Archer.h"


class Monster : public Entity{
public:
    Monster(const string& n, int hp) : Entity(n, hp){
        addAbility(new HeavySlash());
    }
};

//-----------------------
// COMBAT
//-----------------------

class Combat{
    vector<Entity*> participants;
    int round = 1;
public:
    void addParticipant(Entity* e){
        participants.push_back(e);
    }
    void runUnitilOver(int maxRounds = 20){
        while (maxRounds-- >0 && !isOver())
        {
            runRound();
        }
        announceResult();
    }
private:
    void runRound(){
        cout<<"\n**************************\n";
        cout<<"     ROUND<<"<<round++<<"   \n";
        cout<<"\n**************************\n";
    
        for(auto* actor : participants){
            if (!actor-> isAlive()) continue;

            //status effects
            actor->applyEffects();

            if(actor->frozenThisTurn){
                cout<<"  "<<actor->name <<"frozen this Turn\n";
            }

            //cooldowns
            actor->tickAllColldowns();

            //choose a target and attack it
            Entity* target = findOpponnet(actor);
            if (!target) continue;
            cout<<"\n -> Turn"<<actor->name<<"(Attack"<<target-> name<<")\n";
            if (actor->isPlayer){
                
                // choice skill
                cout << "\n" << actor->name << " choice skill:\n";
                for (int i = 0; i < (int)actor->abilities.size(); i++)
                    cout << "  [" << i+1 << "] " << actor->abilities[i]->getName() << "\n";
                int skillChoice;
                cin >> skillChoice;
                skillChoice--;
                if (skillChoice < 0 || skillChoice >= (int)actor->abilities.size()) skillChoice = 0;
                
                // choice target
                vector<Entity*> enemies;
                for (auto* e : participants)
                    if (e != actor && e->isAlive()) enemies.push_back(e);
                
                cout << "\n choice target:\n";
                for (int i = 0; i < (int)enemies.size(); i++)
                    cout << "  [" << i+1 << "] " << enemies[i]->name << "\n";
                int targetChoice;
                cin >> targetChoice;
                targetChoice--;
                if (targetChoice < 0 || targetChoice >= (int)enemies.size()) targetChoice = 0;

                actor->useAbility(skillChoice, *enemies[targetChoice]);
            } else {
                
                // enemy auto
                for (int i = 0; i < (int)actor->abilities.size(); i++)
                    if (actor->useAbility(i, *target)) break;
            }
        }    
        // show status
        cout<<"\n********* status *********\n";
        for(auto* e : participants) e->printStatus();
    }

    Entity* findOpponnet(Entity* actor){
        for(auto*e : participants)
            if(e != actor && e-> isAlive()) return e;
        return nullptr;
    }

    bool isOver()const{
        int alive=0;
        for(auto* e : participants)
            if (e->isAlive()) alive++;
        return alive <= 1;
    }

    void announceResult()const{
        cout<<"\n**************************\n";
        for(auto* e: participants){
            if(e->isAlive()){
                cout<<"     the winner: <<"<<e->name<<"\n";
                cout<<"\n**************************\n";
                return;
            }
        }
        cout<<"      it's Draw     "<<"\n";  
        cout<<"\n**************************\n";
    }
};
