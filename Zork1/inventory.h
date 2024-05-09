#ifndef INVENTORY_H
#define INVENTORY_H

#include "item.h"
#include <vector>
#include "entity.h"
class Character;
class Inventory //: public Entity
{
private:
    //FRIENDSHIP
    friend class Character;
    vector<Item> inventory;
public:
    Inventory();

//    void abstractMethod();

    vector<Item> getInventory(){return inventory;}
    void addToInventory(Item item);
    void removeFromInventory(Item item);
    bool isInInventory(Item item);
    void printInventory();
};

#endif // INVENTORY_H
