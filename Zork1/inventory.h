#ifndef INVENTORY_H
#define INVENTORY_H

#include "item.h"
#include <vector>

class Inventory
{
private:
    vector<Item> inventory;
public:
    Inventory();

    vector<Item> getInventory();
    void addToInventory(Item item);
    void removeFromInventory(Item item);
    bool isInInventory(Item item);
};

#endif // INVENTORY_H
