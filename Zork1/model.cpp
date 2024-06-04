#include <iostream>
#include "model.h"
#include <algorithm>

Model::Model() {
    currentRoomIndex = 2;
}

void Model::addItem(Item newItem) {
    auto iterate = std::find(allItems.begin(), allItems.end(), newItem);
    // Check if the value was found
    if (!(iterate != allItems.end())) {
        allItems.push_back(newItem);
        std::cout << "Item added to inventory." << std::endl;
    }else {
        std::cout << "This is already in your inventory" << endl;
    }
}

void Model:: removeItem(Item newItem){
    auto iterate = std::find(allItems.begin(), allItems.end(), newItem);
    // Check if the value was found
    if (iterate != allItems.end()) {
        // Erase the element at the found iterator
        allItems.erase(iterate);
        std::cout << newItem.getName() << " deleted." << std::endl;
    } else {
        std::cout << "Item doesnt exits." << std::endl;
    }
}

void Model::changeRoom(int roomIndex){
    setCurrentRoomIndex(roomIndex);

}
void Model::setCurrentRoomIndex(int newIndex){
    currentRoomIndex = newIndex;
}
int Model::getCurrentRoomIndex(){
    return currentRoomIndex;
}



