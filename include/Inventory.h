#pragma once
#include <vector>
#include <string>

class Item;

class Inventory {
private:
    std::vector<Item*> items;
    static const int MAX_SLOTS = 5;

public:
    ~Inventory();
    bool  addItem(Item* item);
    void  removeItem(int index);
    void  useItem(int index);
    bool  isFull()  const;
    int   getSize() const;
    Item* getItem(int index) const;
    void  display() const;
};