#pragma once
#include <string>

class Entity; 

class Item {
public:
    virtual ~Item() = default;

    virtual void use(Entity& target) = 0;
    virtual std::string getName() const = 0;
    virtual std::string getDescription() const = 0;
    virtual int getValue() const = 0;

protected:
    std::string name;
    std::string description;
    int value;
};