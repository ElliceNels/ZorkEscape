#ifndef INVENTORY_H
#define INVENTORY_H

#include "item.h"
#include <vector>

class Character;
class Inventory
{
private:
    //FRIENDSHIP
    friend class Character;
    std::vector<Item> inventory;
public:
    Inventory();

    std::vector<Item> getInventory(){return inventory;}
    void addToInventory(Item item);
    void removeFromInventory(Item item);
    bool isInInventory(Item item);
    void printInventory();
};

#endif // INVENTORY_H
