#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include "room.h"
#include "inventory.h"
#include "entity.h"

using namespace std;
class Character //: public Entity
{
private:
    Room location;
    Inventory inventory;

public:
    Character();

    void abstractMethod();

    Room getLocation();
    void setLocation(Room location);

    Inventory getInventory();
    void setInventory(Inventory inventory);

};

#endif // CHARACTER_H
