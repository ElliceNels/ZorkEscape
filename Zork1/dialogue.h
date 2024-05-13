#ifndef DIALOGUE_H
#define DIALOGUE_H

#include <string>
using namespace std;

class Dialogue
{
protected:
    const string failedDoorAccess = "You cannot open this door";
    const string enterRoom = "You just entered a room";
    const string itemPickUp = "You just picked up an item";
    const string placeholder = "";
    const string placeholder1 = "";
    const string placeholder2 = "";
    const string placeholder3 = "";

public:
    string getFailedDoorAccess(){
        return failedDoorAccess;
    }

    string getEnterRoom(){
        return enterRoom;
    }

    string getItemPickUp(){
        return itemPickUp;
    }

    string getPlaceholder(){
        return placeholder;
    }

    string getPlaceholder1(){
        return placeholder1;
    }

    string getPlaceholder2(){
        return placeholder2;
    }

    string getPlaceholder3(){
        return placeholder3;
    }


};

#endif // DIALOGUE_H
