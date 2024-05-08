#include "item.h"
#include "iostream"
Item::Item(int id, string name) {
    this->id = id;
    this->name = name;
}

//void abstractMethod() {
//    cout << "test abstract item" << endl;
//}

// Overloaded equality operator
bool Item:: operator==(const Item& item) const {
    // Compare the names of 'this' and 'other' Item objects
    return this->name == item.name;
}