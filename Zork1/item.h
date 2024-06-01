#ifndef ITEM_H
#define ITEM_H

#include <string>
#include "entity.h"
#include "Interactable.h"
// #include "character.h"
class Room;
//NAMESPACES
using namespace std;
//MULTIPLE INHERITANCE
class Item : public Interactable,  public Entity
{
private:
    int id;
    Room* location;

public:
    Item (int id, string name, string description, Room* location);

    //OPERATOR OVERLOADING
    bool operator==(const Item& item) const;

    inline int getId(){return id;}
    void setId(int id){this->id = id;}


    void Move(Room* newLocation) override;

    virtual string printNameAndDescription() override;
};

#endif // ITEM_H
