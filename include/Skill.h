#pragma once
#include <string>

class Entity;

class Skill {
protected:
    std::string name_;
    int         manaCost_;
    int         power_;
    std::string description_;

public:
    Skill(const std::string& name, int manaCost, int power, const std::string& description)
        : name_(name), manaCost_(manaCost), power_(power), description_(description) {}

    virtual ~Skill() = default;

    virtual void use(Entity& caster, Entity& target) const = 0;

    std::string getName() const { return name_; }
    int         getManaCost() const { return manaCost_; }
    int         getPower() const { return power_; }
    std::string getDescription() const { return description_; }
};
