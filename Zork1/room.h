#ifndef ROOM_H
#define ROOM_H

#include <vector>
#include <map>
#include "string"
#include "item.h"

class Entity;


class Room : public Entity
{
private:
    int roomId;
    std::string description;
    std::vector<Item> itemsInRoom;
    std::map<std::string, Room*> exits;

public:
    Room(int roomId, std::string name, std::string description);

//    void abstractMethod();

    int getRoomId(){ return roomId;}
    void setRoomId(int roomId){ this->roomId = roomId;}

    map<string, Room*> getExits(){return exits;};
    void setExits(Room *north, Room *east, Room *south, Room *west);

    std::vector<Item> getItemsInRoom(){  return itemsInRoom;}
    void addItemToRoom(Item item);
    void removeItemFromRoom(Item item);

    void printItemsInRoom();
    void printRoom();

    virtual void printNameAndDescription() override;
    //CONTINUE HERE


};

#endif // ROOM_H
