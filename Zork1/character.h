#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <utility>
#include "room.h"
#include "inventory.h"
#include "entity.h"

using namespace std;
class Character //: public Entity
{
private:
    Room *location;
    Inventory inventory;

public:
    Character();

    void abstractMethod();

    inline Room* getLocation(){ return location;}
    inline void setLocation(Room* location){this->location = location;}

    vector<Item> getInventory(){return inventory.inventory;};
    void setInventory(Inventory inventory){ this->inventory = std::move(inventory);}


    void addToInventory(Item item);
    void removeFromInventory(Item item);
    bool isInInventory(Item item);
    void printInventory();

};

#endif // CHARACTER_H
