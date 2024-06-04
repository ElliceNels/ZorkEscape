#include <algorithm>
#include <iostream>
#include "room.h"

 // INITIALISER LIST
 Room::Room(int roomId, string name, string description) : roomId(roomId){
    setName(name);
    setDescription(description);
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

string Room:: printItemsInRoom(){
    // Output elements of the vector using an iterator
    for (auto it = itemsInRoom.begin(); it != itemsInRoom.end(); ++it) {
        it->printNameAndDescription();
    }
    return std::to_string(itemsInRoom.size()) + " items in the room." + "\n" + printNameAndDescription();
}

string Room::printRoomItemDetails(){
    string totalText = "";
    for (auto it = itemsInRoom.begin(); it != itemsInRoom.end(); ++it) {
        totalText = totalText + it->printNameAndDescription();
    }
    return totalText;
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


string Room:: printNameAndDescription(){
    return getName() + ": " + getDescription();
}

//DEEP COPY CONSTRUCTOR AND C++ REFERENCES
Room::Room(const Room& other) : Entity(other), roomId(other.roomId) {
    for (const Item& item : other.itemsInRoom) {
        this->itemsInRoom.push_back(Item(item)); //Item copy constructor
    }

    // Copy exits
    for (const auto& exit : other.exits) {
        this->exits[exit.first] = new Room(*(exit.second));
    }
}

Item Room::findItemWithId( int ID){
    for (Item item : getItemsInRoom()){
        if (item.getId() == ID)
            return item;
    };
}


