#include "room.h"
#include "mainwindow.h"
#include "character.h"
#include <iostream>
#include <QApplication>

Room* globRooms[11];
void roomCreation();

int main(int argc, char *argv[])
{
    roomCreation();
    Character mainCharacter;
    mainCharacter.setLocation(globRooms[0]);
    Room* r = mainCharacter.getLocation();
    cout << r->getRoomId() << endl;


   QApplication a(argc, argv);
   MainWindow w;
   w.show();
    return a.exec();
}

void roomCreation(){

    // 11 rooms total
    Room *waitRoom, *doorRoom, *nRoom1, *nRoom2, *keyRoom, *NRoom, *LRoom, *nRoom, *rRoom, *cRoom, *qRoom;

    waitRoom = new Room(3, "Waiting Room", "ROOM W STUFF");
    doorRoom = new Room(4, "Doors Room", "ROOM W STUFF");
    nRoom1 = new Room(5, "placeholder", "ROOM W STUFF");
    nRoom2 = new Room(6, "placeholder", "ROOM W STUFF");
    keyRoom = new Room(7, "Key Room", "ROOM W STUFF");
    NRoom = new Room(8,"NRoom", "ROOM W STUFF");
    nRoom = new Room(9, "nRoom", "ROOM W STUFF");
    LRoom = new Room(10, "LRoom", "ROOM W STUFF");
    cRoom = new Room(11, "cRoom", "ROOM W STUFF");
    rRoom = new Room(12, "rRoom", "ROOM W STUFF");
    qRoom = new Room(13, "Exit Room", "ROOM W STUFF");

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
