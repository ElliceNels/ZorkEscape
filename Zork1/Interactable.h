#ifndef INTERACTABLE_H
#define INTERACTABLE_H

#include "room.h"

//ABSTRACT CLASS
class Interactable {
private:
    Room* location;
public:
    // VIRTUAL FUNCTION
    virtual void Move(Room* newLocation) = 0;

    inline Room* getLocation(){ return location;}
    inline void setLocation(Room* location){this->location = location;}
};

#endif // INTERACTABLE_H
