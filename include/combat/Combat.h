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
// ARCHER ABILITIES
//-----------------------

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
        for(int i; i < ARROWS; i++){
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
