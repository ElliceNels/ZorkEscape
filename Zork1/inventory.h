#ifndef INVENTORY_H
#define INVENTORY_H

#include "item.h"
#include <vector>

class Character;
//TEMPLATE CLASS
template <typename T>
class Inventory
{
private:
    //FRIENDSHIP -> it is given, not taken -> Inventory makes Character a friend (giving it access)
    friend class Character;
    std::vector<T> inventory;
public:
    Inventory();

    std::vector<T> getInventory(){return inventory;}
    void addToInventory(Item item);
    void removeFromInventory(Item item);
    bool isInInventory(Item item);
    void printInventory();
};

#endif // INVENTORY_H
