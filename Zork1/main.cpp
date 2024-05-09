#include "mainwindow.h"
#include "character.h"
#include <iostream>
//#include <QApplication>

int main(int argc, char *argv[])
{

//    Item item2(2, "key2");

    Item item1(1, "key1");
    Character chard;
    Room *rooma = new Room(2, "Room A");

//    Room *roomb = new Room(3, "Room B");
//    Room *roomc = new Room(4, "Room C");



//    chard.getCharInventory().addToInventory(item1);
//    chard.getCharInventory().printInventory();
//    cout << chard.getCharInventory().getInventory().empty();

//    Inventory vent;
//    vent.printInventory();
//    vent.addToInventory(item1);
//    vent.printInventory();


    Character vent1;
    vent1.printInventory();
    vent1.addToInventory(item1);
    vent1.printInventory();
    vent1.removeFromInventory(item1);
    vent1.printInventory();


    // rooma->getItemsInRoom();

    // rooma->addItemToRoom(item1);

    // cout << rooma->getRoomId();

    // rooma->printItemsInRoom();

    // rooma->setExits(roomb , roomc, NULL, NULL);



//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
    return 0;//a.exec();
}
