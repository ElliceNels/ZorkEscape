#include "room.h"
#include "mainwindow.h"
#include "character.h"
#include <QApplication>

Room *globRooms[6];

int main(int argc, char *argv[])
{
    Character mainCharacter;
    mainCharacter.setLocation(globRooms[0]);



    QApplication a(argc, argv);
    MainWindow w;

    w.show();

    return a.exec();
}


