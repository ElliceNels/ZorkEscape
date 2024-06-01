#include "character.h"
#include <iostream>
#include <algorithm>

 Character::Character() {
    Inventory();
}

 void Character::addToInventory(Item item) {
     // Accessing the private member items of the Inventory class directly
     inventory.inventory.push_back(item);
 }


 void Character:: removeFromInventory(Item item){
     auto iterate = std::find(inventory.inventory.begin(), inventory.inventory.end(), item);
     // Check if the value was found
     if (iterate != inventory.inventory.end()) {
         // Erase the element at the found iterator
         inventory.inventory.erase(iterate);
         std::cout << item.getName() << " removed." << std::endl;
     } else {
         std::cout << "Value not found in the inventory." << std::endl;
     }
}


 void Character:: printInventory(){
     // Output elements of the vector using an iterator

     if (inventory.inventory.empty()){
         std::cout << "Inventory is empty" << endl;
     }else {
         for (auto it = inventory.inventory.begin(); it != inventory.inventory.end(); ++it) {
             std::cout << "Item ID: " << it->getId() << ", '" <<  it->getName() << "' " << endl;
         }
     }

     std::cout << std::endl;
 }

 bool Character::isInInventory(Item item) {
     auto iterate = std::find(inventory.inventory.begin(), inventory.inventory.end(), item);
     // Check if the value was found
     return (iterate != inventory.inventory.end());
 }

  void Character::Move(Room* newLocation) {
     setLocation(newLocation);
     cout << "Location Moved" << endl;
}

  string Character:: printNameAndDescription(){
      cout << "Character - " << getName() << ": " << getDescription() << endl;
  }
