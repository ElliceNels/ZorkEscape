#ifndef ROOM_H
#define ROOM_H

#include "item.h"
#include <vector>
#include <map>
#include "entity.h"

using namespace std;

class Room //: public Entity
{
private:
    int roomId;
    vector<Item> itemsInRoom;
    map<string, Room*> exits;

public:
    Room(int roomId, string description);

    void abstractMethod();

    int getRoomId();
    void setRoomId(int roomId);

    vector<Item> getItemsInRoom();
    void addItemToRoom(Item item);
    void removeItemToRoom(Item item);

};

#endif // ROOM_H
