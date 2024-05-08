#ifndef ROOM_H
#define ROOM_H

#include "item.h"
#include <vector>
#include <map>

using namespace std;

class Room
{
private:
    int roomId;
    vector<Item> itemsInRoom;
    string description;
    map<string, Room*> exits;

public:
    Room(int roomId, string description);

    string getDescription();
    void setDescription();

    int getRoomId();
    void setRoomId(int roomId);

    vector<Item> getItemsInRoom();
    void addItemToRoom(Item item);
    void removeItemToRoom(Item item);

};

#endif // ROOM_H
