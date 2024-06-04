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
    const string victory = "You escaped!! Here are some lollipops. Click the correct one to exit";
    const string placeholder1 = "";
    const string placeholder2 = "";
    const string placeholder3 = "";

public:
    string getFailedDoorAccess(){
        return failedDoorAccess;
    }

    // string getEnterRoom(int itemsInRoom){
    //     return enterRoom + "\nThere are " + itemsInRoom + " items in the room";
    // }

    string getItemPickUp(){
        return itemPickUp;
    }

    string getVictory(){
        return victory;
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
