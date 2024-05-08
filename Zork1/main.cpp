#include "mainwindow.h"
#include "character.h"
#include <iostream>
//#include <QApplication>

int main(int argc, char *argv[])
{
    Item item1(1, "key1");
    Item item2(2, "key2");

    Room rooma(2, "Room A");
    Room roomb(3, "Room B");
    Room roomc(4, "Room C");


    rooma.getItemsInRoom();

    rooma.addItemToRoom(item1);

    cout << rooma.getRoomId();

    rooma.printItemsInRoom();

    rooma.setExits(roomb, roomc, NULL, NULL);



//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
    return 0;//a.exec();
}
