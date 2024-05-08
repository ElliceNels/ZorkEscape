#ifndef ITEM_H
#define ITEM_H

#include <string>
#include "entity.h"

//NAMESPACES
using namespace std;
class Item //: public Entity
{
private:
    int id;
    string name;

public:
    Item (int id, string name);

    //void abstractMethod();

    //OPERATOR OVERLOADING
    bool operator==(const Item& item) const;

    inline int getId(){return id;}
    void setId(int id){this->id = id;}

    inline string getName(){return name;}
    void setName(string name){this->name = name;}
};

#endif // ITEM_H
