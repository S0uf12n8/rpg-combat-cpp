#pragma once
#include "Entity.h"

//-----------------------
// fighter abilities
//-----------------------

//strong attack
class HeavySlash : public Ability{
public:
    HeavySlash() : Ability("Heavy Slash",45,0.60f,3){}
protected:
    void use(Entity& caster, Entity& target)override {
        cout<<" sword attack "<<caster.name<<"Heavy Stroke\n";
        if(rollHit())
            target.takeDamage(damage);
        else
            cout<< " Missed Heavy Cut ";
    }
};

//moderate attack
class VerticalCut:public Ability{
public:
    VerticalCut():Ability("Vertical Cut",35,0.80f,2){}
protected:
    void use(Entity& caster, Entity& target){
        cout<<" sword attack "<<caster.name<<"Medium Stroke\n";
        if(rollHit())
            target.takeDamage(damage);
        else
            cout<< " Missed Vertical Cut ";
    }
};

//Light Stroke
class TripleStrike : public Ability{
public:
    TripleStrike() : Ability("Triple Strike",12,0.85f,3){}
protected:
    void use(Entity& caster, Entity& target){
        for (int i = 0; i < 3; i++){
            if (rollHit()){
                cout <<" attack "<<i<<": ";
                target.takeDamage(damage);}
            else{
                cout<<" attack "<<i<<"Missed attack\n";
            }
        }
    }
};

//-----------------------
// CHARACTER SUBCLASSES
//-----------------------

class Warrior : public Entity{
public:
    Warrior(const string& n): Entity(n, 130){
        addAbility(new HeavySlash());
        addAbility(new VerticalCut());
        addAbility(new TripleStrike());
    }
};