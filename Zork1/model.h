#ifndef MODEL_H
#define MODEL_H

#include "character.h"
extern Room* globRooms;
class Model
{
private:
    Character character;
    vector<Item> allItems;
    int currentRoomIndex;

public:
    Model();
    void addItem(Item newItem);
    void removeItem(Item newItem);
};

#endif // MODEL_H
