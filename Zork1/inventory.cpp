#include "inventory.h"
#include "iostream"
#include <algorithm>

Inventory::Inventory() {
}

//void abstractMethod() {
//    cout << "test abstract inventory" << endl;
//}

void Inventory:: addToInventory(Item item){
    if (!isInInventory(item)) {
        inventory.push_back(item);
        std::cout << "Item added to inventory." << std::endl;
    }else {
        std::cout << "This is already in your inventory" << endl;
    }
}

void Inventory:: removeFromInventory(Item item){
    auto iterate = std::find(inventory.begin(), inventory.end(), item);
    // Check if the value was found
    if (iterate != inventory.end()) {
        // Erase the element at the found iterator
        inventory.erase(iterate);
        std::cout << item.getName() << " removed." << std::endl;
    } else {
        std::cout << "Value not found in the vector." << std::endl;
    }
}

bool Inventory::isInInventory(Item item) {
    auto iterate = std::find(inventory.begin(), inventory.end(), item);
    // Check if the value was found
    return (iterate != inventory.end());
}

void Inventory:: printInventory(){
    // Output elements of the vector using an iterator

    if (inventory.empty()){
        std::cout << "inventory is empty print" << endl;
    }else {
        for (auto it = inventory.begin(); it != inventory.end(); ++it) {
            std::cout << it->getName() << " ";
            std::cout << "Item ID: " << it->getId() << " " << endl;
        }
    }

    std::cout << std::endl;
}
