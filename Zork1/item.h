#ifndef ITEM_H
#define ITEM_H

#include <string>
#include "entity.h"

using namespace std;
class Item //: public Entity
{
private:
    int id;
    string name;

public:
    Item (int id, string name);

    //void abstractMethod();

    inline int getId(){return id;}
    void setId(int id){this->id = id;}
};

#endif // ITEM_H
