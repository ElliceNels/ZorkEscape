#ifndef MODEL_H
#define MODEL_H

#include "character.h"
extern Room* globRooms[11];
class Model
{
private:
    Character character;
    vector<Item> allItems;
    Room* globRooms;
    int currentRoomIndex;

public:
    Model();
    void addItem(Item newItem);
    void removeItem(Item newItem);
};

#endif // MODEL_H
