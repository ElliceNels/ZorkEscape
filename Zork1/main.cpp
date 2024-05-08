#include "mainwindow.h"
#include "character.h"
#include <iostream>
//#include <QApplication>

int main(int argc, char *argv[])
{
    Item item1(1, "key1");
    Item item2(2, "key2");

    Inventory vent;
    vent.addToInventory(item1);
    vent.addToInventory(item2);

    vent.printInventory();

    vent.removeFromInventory(item2);

    vent.printInventory();
    cout << vent.getInventory().size() << endl;



//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
    return 0;//a.exec();
}
