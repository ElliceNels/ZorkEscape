#include "item.h"
#include <iostream>
Item::Item(int id, string name, string description, Room* location) {
    this->id = id;
    this->location = location;
    setName(name);
    setDescription(description);

}

//void abstractMethod() {
//    cout << "test abstract item" << endl;
//}

// OVERLOADED EQUALITY OPERATOR
bool Item:: operator==(const Item& item) const {
    // Compare the names of 'this' and 'other' Item objects
    return (this->id == item.id) && (1); //fix to compare names
}

void Item::Move(Room* newLocation) {
    setLocation(newLocation);
    cout << "Location Moved" << endl;
}

string Item:: printNameAndDescription(){
    return "Item - " + getName() + ": " + getDescription() + "\n";
}
