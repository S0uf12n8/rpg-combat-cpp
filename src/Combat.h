#pragma once
#include "Warrior.h"
#include "Mage.h"
#include "Archer.h"

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
            for (int i = 0; i < (int)actor ->abilities.size(); i++){
                if (actor-> useAbility(i, *target)) break;
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
