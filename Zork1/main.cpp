#include "mainwindow.h"
#include "character.h"
#include <iostream>
//#include <QApplication>

Room* globRooms[11];
void roomCreation();

int main(int argc, char *argv[])
{
    roomCreation();
    Character mainCharacter;
    mainCharacter.setLocation(globRooms[0]);

//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
    return 0;//a.exec();
}

void roomCreation(){

    // 11 rooms total
    Room *waitRoom, *doorRoom, *nRoom1, *nRoom2, *keyRoom, *NRoom, *LRoom, *nRoom, *rRoom, *cRoom, *qRoom;

    waitRoom = new Room(3, "Waiting Room");
    doorRoom = new Room(4, "Doors Room");
    nRoom1 = new Room(5, "placeholder");
    nRoom2 = new Room(6, "placeholder");
    keyRoom = new Room(7, "Key Room");
    NRoom = new Room(8,"NRoom");
    nRoom = new Room(9, "nRoom");
    LRoom = new Room(10, "LRoom");
    cRoom = new Room(11, "cRoom");
    rRoom = new Room(12, "rRoom");
    qRoom = new Room(13, "Exit Room");

    waitRoom->setExits(doorRoom, NULL, NULL, NULL);
    doorRoom->setExits(nRoom1, keyRoom, NULL, nRoom2);
    keyRoom->setExits(NRoom, NULL, LRoom, doorRoom);
    LRoom->setExits(keyRoom, cRoom, NULL, NULL);
    NRoom->setExits(NULL, nRoom, keyRoom, NULL);
    nRoom->setExits(NULL, NULL, cRoom, NRoom);
    cRoom->setExits(nRoom, NULL, rRoom, LRoom);
    rRoom->setExits(cRoom, NULL, NULL, qRoom);

    Room* tempRooms[11] = {waitRoom, doorRoom, nRoom1, nRoom2, keyRoom, NRoom, nRoom, LRoom, cRoom, rRoom, qRoom};
    int count = 0;
    for (auto& room : tempRooms) {
        // Assign values to the global array
        globRooms[count] = room;
        count ++;
    }
}
