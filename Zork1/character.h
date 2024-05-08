#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include "room.h"
#include "inventory.h"

using namespace std;
class Character
{
private:
    string name;
    Room location;
    Inventory inventory;

public:
    Character();

    string getName();
    void setName(string name);

    Room getLocation();
    void setLocation(Room location);

    Inventory getInventory();
    void setInventory(Inventory inventory);

};

#endif // CHARACTER_H
