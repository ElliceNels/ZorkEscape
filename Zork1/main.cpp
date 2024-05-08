#include "mainwindow.h"
#include "character.h"
#include <iostream>
//#include <QApplication>

int main(int argc, char *argv[])
{
    Item i(8,"key");
    cout << i.getId() << ": id";

//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
    return 0;//a.exec();
}
