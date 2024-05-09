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
    string description;
    vector<Item> itemsInRoom;
    map<string, Room*> exits;

public:
    Room(int roomId, string description);

//    void abstractMethod();

    int getRoomId(){ return roomId;}
    void setRoomId(int roomId){ this->roomId = roomId;}

    map<string, Room*> getExits(){return exits;};
    void setExits(Room *north, Room *east, Room *south, Room *west);

    vector<Item> getItemsInRoom(){  return itemsInRoom;}
    void addItemToRoom(Item item);
    void removeItemFromRoom(Item item);

    void printItemsInRoom();
    void printRoom();

};

#endif // ROOM_H
