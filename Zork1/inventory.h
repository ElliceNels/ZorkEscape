#ifndef INVENTORY_H
#define INVENTORY_H

#include "item.h"
#include <vector>
#include "entity.h"

class Inventory //: public Entity
{
private:
    vector<Item> inventory;
public:
    Inventory();

    void abstractMethod();

    vector<Item> getInventory(){return inventory;}
    void addToInventory(Item item);
    void removeFromInventory(Item item);
    bool isInInventory(Item item);
};

#endif // INVENTORY_H
