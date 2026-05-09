#pragma once
#include "Entity.h"

//-----------------------
// MAGE ABILITIES
//-----------------------

// fireball
class Fireball : public Ability{
    int useCount=0;
    static constexpr int DECAY = 5;
    static constexpr int MIN_DMG = 10;
public:
    Fireball():Ability("Fireball",35,0.80f,4){}
protected:
    void use(Entity& caster, Entity& target) override{
        int currentDmg=max(MIN_DMG, damage - useCount*DECAY);
        useCount++;
        cout<<" Fireball Attack "<<caster.name<<"Fireball Launches\n";
        if (rollHit())
            target.takeDamage(currentDmg);
        else
            cout<<"Fireball Attack Missed\n";
    }
};

// freeze
class FreezeSpell : public Ability{
public:
    FreezeSpell() : Ability("Freeze",20,0.75f,2){}
protected:
    void use(Entity& caster, Entity& target) override{
        cout<<" Feeze attack "<< caster.name<<"Feeze Launches\n";
        if(rollHit()){
            target.takeDamage(damage);
            target.addEffect(new FreezeEffect(2));
        }
        else{
            cout<<"Feeze Attack Missed\n";}    
    }
};

// Flash
class Flash : public Ability{
public:
    Flash() : Ability("Flash",60,0.40f,3){}
protected:
    void use(Entity& caster, Entity& target){
         cout<<" Flash attack "<< caster.name<<"Flash Launches\n";
        if(rollHit())
            target.takeDamage(damage);
        else
            cout<<"Flash Attack Missed\n";
    }
};

//-----------------------
// CHARACTER SUBCLASSES
//-----------------------

class Mage : public Entity{
public:
    Mage(const string& n): Entity(n, 80){
        addAbility(new Fireball());
        addAbility(new FreezeSpell());
        addAbility(new Flash());
    }
};