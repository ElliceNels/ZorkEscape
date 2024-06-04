#include "room.h"
#include "mainwindow.h"
#include "character.h"
#include <QApplication>

//GLOBAL VARIABLE
Room *globRooms[6];

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}


