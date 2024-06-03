#ifndef ITEM_H
#define ITEM_H

#include <string>
#include "entity.h"
// #include "character.h"
class Room;
//NAMESPACES
using namespace std;
//MULTIPLE INHERITANCE
class Item : public Entity
{
private:
    int id;

public:
    Item (int id, string name, string description);

    //OPERATOR OVERLOADING
    bool operator==(const Item& item) const;

    inline int getId(){return id;}
    void setId(int id){this->id = id;}

    //DEEP COPY CONSTRUCTOR
    Item(const Item& other);

    virtual string printNameAndDescription() override;
};

#endif // ITEM_H
