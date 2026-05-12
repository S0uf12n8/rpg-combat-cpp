#pragma once
#include <string>

// Item is the "parent" of items in the game
//  Consumable, Weapon, or Armor (LWLAD)

class Item {
protected:
    std::string name;    
    std::string description;
    int value;

public:
    Item(const std::string& name, const std::string& description, int value);

    // garanti que le destructeur  est appele lorsque nous supprimons un enfant
    virtual ~Item() = default;

    // use() is what happens when the player "uses" this item
    virtual void use() = 0;

    virtual std::string getDescription() const;

    std::string getName()  const;
    int         getValue() const;

    friend std::ostream& operator<<(std::ostream& os, const Item& item);
};