#include "Item.h"
#include <iostream>

Item::Item(const std::string& name, const std::string& description, int value)
    : name(name), description(description), value(value)
{
}

//combine name + description
std::string Item::getDescription() const {
    return name + " — " + description;
}

std::string Item::getName()  const { return name; }
int         Item::getValue() const { return value; }

std::ostream& operator<<(std::ostream& os, const Item& item) {
    os << item.getDescription();
    return os;
}