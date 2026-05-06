#pragma once
#include "Entity.h"

// Power Arrow
class PowerArrow : public Ability{
public:
    PowerArrow() : Ability("Power Arrow",48,0.75f,3){}
protected:
    void use(Entity& caster, Entity& target){
        cout<<" Power Arrow Attack "<<caster.name<<"Power Arrow Launches\n";
        if(rollHit())
            target.takeDamage(damage);
        else
            cout<< "Arrow Attack Missed\n";
    }
};

// Multi Arrow
class MultiArrow : public Ability{
    static constexpr int ARROW_DMG = 18;
    static constexpr int ARROWS = 3;
public:
    MultiArrow() : Ability("Multi Arrow",ARROW_DMG,0.80f,2){}
protected:
    void use(Entity& caster, Entity& target)override{
        cout<<" Multi Arrow Attack "<<caster.name<<"Multi Launches"<<ARROWS<<"Arrow\n";
        int total =0;
        for(int i=0; i < ARROWS; i++){
            if (rollHit()){
                cout<<" Arrow "<<i<<": ";
                target.takeDamage(ARROW_DMG);
                total+= ARROW_DMG;
            }else{
                cout<<"Arrow Attack Missed\n";
            }
        }
        cout<<"total damage: "<<total<<"\n";
    }
};

//-----------------------
// CHARACTER SUBCLASSES
//-----------------------

class Archer : public Entity{
public:
    Archer(const string& n): Entity(n, 100){
        addAbility(new PowerArrow());
        addAbility(new MultiArrow());
    }
};