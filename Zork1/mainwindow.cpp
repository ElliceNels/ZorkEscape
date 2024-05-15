#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "room.h"
#include "item.h"
extern Room *globRooms[11];

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    AllPages = ui->AllPages;
    AllPages->setCurrentIndex(0);

}

// DESTRUCTOR
MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_PlayButton_clicked()
{
    AllPages->setCurrentIndex(1);
}

void MainWindow::initiateGame(){
    roomCreation();

}

void MainWindow::on_continueButton_clicked()
{
    initiateGame();
    AllPages->setCurrentIndex(2);
}

void MainWindow::roomCreation(){

    // 11 rooms total
    Room *waitRoom, *doorRoom, *nRoom1, *nRoom2, *keyRoom, *NRoom, *LRoom, *nRoom, *rRoom, *cRoom, *qRoom;

    waitRoom = new Room(2, "Waiting Room", "ROOM W STUFF");
    doorRoom = new Room(3, "Doors Room", "ROOM W STUFF");
    nRoom1 = new Room(4, "placeholder", "ROOM W STUFF");
    nRoom2 = new Room(5, "placeholder", "ROOM W STUFF");
    keyRoom = new Room(6, "Key Room", "ROOM W STUFF");
    NRoom = new Room(7,"NRoom", "ROOM W STUFF");
    nRoom = new Room(8, "nRoom", "ROOM W STUFF");
    LRoom = new Room(9, "LRoom", "ROOM W STUFF");
    cRoom = new Room(10, "cRoom", "ROOM W STUFF");
    rRoom = new Room(11, "rRoom", "ROOM W STUFF");
    qRoom = new Room(12, "Exit Room", "ROOM W STUFF");

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


void MainWindow::fillRooms(){

}

void MainWindow::itemCreation(){
    Room *keyRoom = globRooms[1];
    Item item1R1 = *new Item(1, "Key", "An old rustic key", keyRoom);
    Item item2R1 = *new Item(2, "Key", "The key to a door of some sort", keyRoom);
    Item item3R1 = *new Item(3, "Key", "A key with unknown use", keyRoom);
    Item item4R1 = *new Item(4, "Key", "This key does nothing", keyRoom);
    Item item5R1 = *new Item(5, "Key", "A key with an inscription, '9274'", keyRoom);
    Item item6R1 = *new Item(6, "Key", "unknown", keyRoom);
    Item item7R1 = *new Item(7, "Key", "A very dirty key", keyRoom);
    Item item8R1 = *new Item(8, "Key", "Key to a lock", keyRoom);

    Room *doorsRoom = globRooms[2];
    Item item1R2 = *new Item(1, "Key-Card", "A key-card with no barcode", doorsRoom);
    Item item2R2 = *new Item(2, "Key-Card", "Wait this is a piece of paper", doorsRoom);
    Item item3R2 = *new Item(3, "Key-Card", "A key-card", doorsRoom);
    Item item4R2 = *new Item(4, "Key-Card", "A high-tech card with all access", doorsRoom);
    Item item5R2 = *new Item(5, "Key-Card", "A key-card in the shape of a key", doorsRoom);




}

// Things to happen to initiate game
// - create rooms
// - fill rooms with items
// - set current room to room with id 3 (current room = globRooms[idWanted-1]) - may be unneccessary
// - create character
// - Switch character location to current room





    //ui->Character->hide();


