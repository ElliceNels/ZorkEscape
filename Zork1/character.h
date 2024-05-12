#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <utility>
#include "room.h"
#include "inventory.h"
#include "entity.h"

using namespace std;
// INHERITANCE
class Character : public Interactable //: public Entity
{
private:
    Inventory inventory;

public:
    Character();

    void abstractMethod();


    vector<Item> getInventory(){return inventory.inventory;};
    void setInventory(Inventory inventory){ this->inventory = std::move(inventory);}


    void addToInventory(Item item);
    void removeFromInventory(Item item);
    bool isInInventory(Item item);
    void printInventory();

    void Move(Room* newLocation) override;


};

#endif // CHARACTER_H
