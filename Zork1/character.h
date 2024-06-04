#ifndef CHARACTER_H
#define CHARACTER_H

#include "inventory.h"
// #include "entity.h"
#include "Interactable.h"

class Room;
using namespace std;
// INHERITANCE
class Character : public Interactable, public Entity
{
private:
    Inventory <Item> inventory;

public:
    Character();

    void abstractMethod();


    vector<Item> getInventory(){return inventory.inventory;};
    void setInventory(Inventory<Item> inventory){ this->inventory = std::move(inventory);}


    void addToInventory(Item item);
    void removeFromInventory(Item item);
    bool isInInventory(Item item);
    bool isInInventory(int ID);
    void printInventory();

    void Move(Room* newLocation) override;

    virtual string printNameAndDescription() override;


};

#endif // CHARACTER_H
