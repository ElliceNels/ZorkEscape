#ifndef MODEL_H
#define MODEL_H
#include <map>
#include "character.h"
extern Room* globRooms[6];
class Model
{
private:
    vector<Item> allItems;
    // union current{
        Character character;
        Room* globRooms;
        int currentRoomIndex;
    // };


public:
    Model();
    void addItem(Item newItem);
    void removeItem(Item newItem);
    void changeRoom(int roomIndex);
    void setCurrentRoomIndex(int newIndex);
    int getCurrentRoomIndex();
};

#endif // MODEL_H
