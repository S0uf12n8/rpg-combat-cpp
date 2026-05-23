#include "Inventory.h"
#include "Item.h"
#include <iostream>

bool Inventory::addItem(Item* item) {
    if (isFull()) {
        std::cout << "Inventory is full (max " << MAX_SLOTS << " items)\n";
        return false;
    }
    items.push_back(item);
    std::cout << item->getName() << " added to inventory\n";
    return true;
}

void Inventory::removeItem(int index) {
    if (index < 0 || index >= (int)items.size()) {
        std::cout << "Invalid index\n";
        return;
    }
    std::cout << items[index]->getName() << " removed from inventory\n";
    items.erase(items.begin() + index);
}

void Inventory::useItem(int index) {
    if (index < 0 || index >= (int)items.size()) {
        std::cout << "Invalid index\n";
        return;
    }
    items[index]->use();
    removeItem(index);
}

bool Inventory::isFull() const {
    return (int)items.size() >= MAX_SLOTS;
}

int Inventory::getSize() const {
    return (int)items.size();
}

Item* Inventory::getItem(int index) const {
    if (index < 0 || index >= (int)items.size()) {
        return nullptr;
    }
    return items[index];
}

void Inventory::display() const {
    if (items.empty()) {
        std::cout << "Inventory is empty.\n";
        return;
    }
    for (int i = 0; i < (int)items.size(); i++)
        std::cout << "[" << i << "] "
                  << items[i]->getName() << "\n";
}