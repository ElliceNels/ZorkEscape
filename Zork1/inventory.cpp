#include "inventory.h"
#include "iostream"

Inventory::Inventory() {
}

//void abstractMethod() {
//    cout << "test abstract inventory" << endl;
//}

void Inventory:: addToInventory(Item item){
    inventory.push_back(item);
}

void Inventory:: removeFromInventory(Item item){
    inventory.push;
}