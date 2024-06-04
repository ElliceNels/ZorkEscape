#include "inventory.h"
#include <iostream>
#include <algorithm>

template <typename T>
Inventory<T>::Inventory() {
}

template <typename T>
void Inventory<T>:: addToInventory(Item item){
    if (!isInInventory(item)) {
        inventory.push_back(item);
        std::cout << "Item added to inventory." << std::endl;
    }else {
        std::cout << "This is already in your inventory" << endl;
    }
}

template <typename T>
void Inventory<T>:: removeFromInventory(Item item){
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

template <typename T>
bool Inventory<T>::isInInventory(Item item) {
    auto iterate = std::find(inventory.begin(), inventory.end(), item);
    // Check if the value was found
    return (iterate != inventory.end());
}

template <typename Item>
bool Inventory<Item>::isInInventory(int ID) {
    auto it = std::find_if(inventory.begin(), inventory.end(), [ID](Item& item) {
        return item.getId() == ID;
    });
    return (it != inventory.end());
}

template <typename T>
void Inventory<T>:: printInventory(){
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

template class Inventory<Item>;
