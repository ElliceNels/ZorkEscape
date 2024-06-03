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
    std::vector<Item> itemsInRoom;
    std::map<std::string, Room*> exits;

public:
    Room(int roomId, std::string name, std::string description);


    int getRoomId(){ return roomId;}
    void setRoomId(int roomId){ this->roomId = roomId;}

    map<string, Room*> getExits(){return exits;};
    void setExits(Room *north, Room *east, Room *south, Room *west);

    std::vector<Item> getItemsInRoom(){  return itemsInRoom;}
    void addItemToRoom(Item item);
    void removeItemFromRoom(Item item);

    string printItemsInRoom();
    string printRoomItemDetails();

    virtual string printNameAndDescription() override;

    //DEEP COPY CONSTRUCTOR
    Room(const Room& other);


};

#endif // ROOM_H
