#include <algorithm>
#include <iostream>
#include "room.h"

 Room::Room(int roomId, string description) {
    this->roomId = roomId;
    this->description = description;
}

 void Room::addItemToRoom(Item item){
    itemsInRoom.push_back(item);
}

 void Room::removeItemFromRoom(Item item){
     auto iterate = std::find(itemsInRoom.begin(), itemsInRoom.end(), item);
     // Check if the value was found
     if (iterate != itemsInRoom.end()) {
         // Erase the element at the found iterator
         itemsInRoom.erase(iterate);
         std::cout << item.getName() << " removed from room" << std::endl;
     } else {
         std::cout << "Item not found in the room." << std::endl;
     }
 }

void Room:: printItemsInRoom(){
    // Output elements of the vector using an iterator
    for (auto it = itemsInRoom.begin(); it != itemsInRoom.end(); ++it) {
        std::cout << it->getName() << " " << endl;
        std::cout << "Item ID: " << it->getId() << " " << endl;
    }

    std::cout << std::endl;
}



void Room::setExits(Room *north, Room *east, Room *south, Room *west){
    if (north != NULL)
        exits["north"] = north;
    if (east != NULL)
        exits["east"] = east;
    if (south != NULL)
        exits["south"] = south;
    if (west != NULL)
        exits["west"] = west;
} //implement

