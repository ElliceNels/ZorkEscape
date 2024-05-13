#include "item.h"
#include <iostream>
Item::Item(int id, string name, string description) {
    this->id = id;
    setName(name);
    setDescription(description);
}

//void abstractMethod() {
//    cout << "test abstract item" << endl;
//}

// OVERLOADED EQUALITY OPERATOR
bool Item:: operator==(const Item& item) const {
    // Compare the names of 'this' and 'other' Item objects
    return this->id == item.id;
}

void Item::Move(Room* newLocation) {
    setLocation(newLocation);
    cout << "Location Moved" << endl;
}

void Item:: printNameAndDescription(){
    cout << "Item - " << getName() << ": " << getDescription() << endl;
}
