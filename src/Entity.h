#pragma once
#include<iostream>
#include<string>
#include <algorithm>
#include<cstdlib>
#include<ctime>
#include<vector>
using namespace std;

//-----------------------
// declaration
//-----------------------
class Entity;
class Ability;

//-----------------------
// Status Effect
//-----------------------
class StatusEffect{
protected:
    string name;
    int duration;

public:
    StatusEffect(string n, int d): name(n), duration(d){}
    
    virtual void apply(Entity& target)=0;
    void reduceDuration(){
        duration--;
    }

    bool Expired()const {
        return duration <=0;
    }
     string getName() const{
        return name;
    }
    int getDuration()const{
        return duration;
    }
    virtual ~StatusEffect() {};
};

//-----------------------
// Ability
//----------------------

class Ability{
protected:
    string name;
    int damage;
    float accuracy;
    int cooldownMax;
    int cooldownTimer;

public:
    Ability(const string& n, int dmg, float acc, int cd): name(n), damage(dmg), accuracy(acc),
    cooldownMax(cd), cooldownTimer(0) {}
    void tickCooldown(){
        if (cooldownTimer>0){
            cooldownTimer--;
        }
    }
    bool Ready()const{return cooldownTimer==0;}
    bool tryUse(Entity& caster, Entity& target){
        if (!Ready())
        {
            cout<<"["<<name<<"]"<<cooldownTimer<<"turn.\n";
            return false;
        }
        use(caster, target);
        cooldownTimer=cooldownMax;
        return true;
    }
    string getName() const{return name;}
    virtual ~Ability() {}
protected:
    virtual void use(Entity& caster, Entity& target)=0;
    
    bool rollHit()const{
        return (static_cast<float>(rand())/ RAND_MAX) <= accuracy;
    }
};

//-----------------------
// Entity
//-----------------------


class Entity{

    public:
    string name;
    int hp;
    int maxHp;
    bool frozenThisTurn=false;
    
    vector<StatusEffect*> effects;
    vector<Ability*> abilities;

    Entity(const string& n, int h):name(n), hp(h), maxHp(h) {}

    void takeDamage(int dmg){
        hp=max(0,hp-dmg);
        cout<<"   "<<name<<" receive "<<dmg<<"damege (HP: "<<hp<<"/"<<maxHp <<")\n";
    }

    bool isAlive() const{return hp>0;}

    void addEffect(StatusEffect* e){
        cout<< " warning "<<name<<" infenction "<< e->getName()<<"!\n";
        effects.push_back(e);
    }

    void applyEffects(){
        frozenThisTurn = false;
        for (auto* e :effects){
            e->apply(*this);
            e->reduceDuration();
        }
    
        effects.erase(
            remove_if(effects.begin(), effects.end(),[](StatusEffect* e){
                return e->Expired();
            }
        ),
        effects.end()
        );
    }

    void addAbility(Ability* a){
        abilities.push_back(a);
    }

    bool useAbility(int i, Entity& target){
        if(i<0 || i>= (int)abilities.size()) return false;
        return abilities[i]->tryUse(*this, target);
    }
    void tickAllColldowns(){
        for(auto* a : abilities) a->tickCooldown();
    }
    void printStatus() const{
        cout<<" ["<<name<<"] HP: "<< hp <<"/"<<maxHp;
        if(!effects.empty()){
            cout<<" |Effects: ";
            for (auto* e : effects)
                cout<<e->getName() <<"("<<e->getDuration()<<") ";
        }
        cout<<"\n";
    }
    virtual ~Entity() {}
};

//-----------------------
// STATUS EFFECTS
//-----------------------
    //-----------------------
    // Poison Effect
    //-----------------------

class PoisonEffect : public StatusEffect{
    int damagePerTurn;
public:
    PoisonEffect(int d, int duration):StatusEffect("Poison", duration),damagePerTurn(d){}
    void apply(Entity& target) override{
        cout<<"Poison deals"<<damagePerTurn<<"damage!\n";
        target.takeDamage(damagePerTurn);
    }
};
    //-----------------------
    // Freeze Effect
    //-----------------------
class FreezeEffect : public StatusEffect{
public:
    FreezeEffect(int dur) : StatusEffect("Freeze", dur){}
    void apply(Entity& target) override{
        cout <<" Freeze "<<target.name<<"Freezed\n";
        target.frozenThisTurn = true;
    }
};