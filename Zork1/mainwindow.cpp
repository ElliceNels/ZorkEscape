#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "room.h"
#include "item.h"
extern Room *globRooms[6];

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

void MainWindow::initiateGame(){
    roomCreation();
    itemCreation();

}

void MainWindow::changeRoom(int index,  QLabel *label1,  QLabel *label2){
    AllPages->setCurrentIndex(index);
    setLabelText(globRooms[index -2]->printItemsInRoom(), label1);
    setLabelText(globRooms[index -2]->printRoomItemDetails(), label2);
}

void MainWindow::setLabelText(std::string text, QLabel *label)
{
    label->setText(QString::fromStdString(text));
}

void MainWindow::roomCreation(){

    // 6 rooms total
    Room *waitRoom, *keyRoom, *keycardRoom, *buttonRoom, *stickRoom, *lollipopRoom;

    waitRoom = new Room(2, "Waiting Room", "ROOM W STUFF");
    keyRoom = new Room(3, "Key Room", "ROOM W STUFF");
    keycardRoom = new Room(4, "KeyCard Room", "ROOM W STUFF");
    buttonRoom = new Room(5, "Button Room", "ROOM W STUFF");
    stickRoom = new Room(6, "Stick Room", "ROOM W STUFF");
    lollipopRoom = new Room(7, "Lollipop Room", "ROOM W STUFF");
    // (N, e, s, w)
    waitRoom->setExits(keyRoom, NULL, NULL, NULL);
    keyRoom->setExits(buttonRoom, stickRoom, NULL, keycardRoom);
    keycardRoom->setExits(NULL, NULL, lollipopRoom, keyRoom);
    lollipopRoom->setExits(keyRoom, NULL, NULL, NULL);
    stickRoom->setExits(NULL, keyRoom, NULL, NULL);
    buttonRoom->setExits(NULL, NULL, keyRoom, NULL);

    Room* tempRooms[6] = {waitRoom, keyRoom, keycardRoom, buttonRoom, stickRoom, lollipopRoom};
    int count = 0;
    for (auto& room : tempRooms) {
        // Assign values to the global array
        globRooms[count] = room;
        count ++;
    }

}

void MainWindow::itemCreation(){
    Room *keyRoom = globRooms[1];
     globRooms[1]->addItemToRoom(*new Item(1, "Key", "An old rustic key", keyRoom));
     globRooms[1]->addItemToRoom(*new Item(2, "Key", "The key to a door of some sort", keyRoom));
     globRooms[1]->addItemToRoom(*new Item(3, "Key", "A key with unknown use", keyRoom));
     globRooms[1]->addItemToRoom(*new Item(4, "Key", "This key does nothing", keyRoom));
     globRooms[1]->addItemToRoom(*new Item(5, "Key", "A key with an inscription, '9274'", keyRoom));
     globRooms[1]->addItemToRoom(*new Item(6, "Key", "unknown", keyRoom));
     globRooms[1]->addItemToRoom(*new Item(7, "Key", "A very dirty key", keyRoom));
     globRooms[1]->addItemToRoom(*new Item(8, "Key", "Key to a lock", keyRoom));

    Room *keycardRoom = globRooms[2];
   globRooms[2]->addItemToRoom(*new Item(9, "Key-Card", "A key-card with no barcode", keycardRoom));
    globRooms[2]->addItemToRoom(*new Item(10, "Key-Card", "Wait this is a piece of paper", keycardRoom));
     globRooms[2]->addItemToRoom( *new Item(11, "Key-Card", "A key-card", keycardRoom));
    globRooms[2]->addItemToRoom(*new Item(12, "Key-Card", "A high-tech card with all access", keycardRoom));
     globRooms[2]->addItemToRoom(*new Item(13, "Key-Card", "A key-card in the shape of a key", keycardRoom));

    Room *buttonRoom = globRooms[3];
     globRooms[3]->addItemToRoom(*new Item(14, "Button", "A flat button", buttonRoom));
    globRooms[3]->addItemToRoom(*new Item(15, "Button", "A pressy thingy", buttonRoom));
    globRooms[3]->addItemToRoom(*new Item(16, "Button", "Boopy boopy", buttonRoom));
    globRooms[3]->addItemToRoom(*new Item(17, "Button", "A button that is very red", buttonRoom));
    globRooms[3]->addItemToRoom(*new Item(18, "Button", "A pressible button", buttonRoom));

    Room *stickRoom = globRooms[4];
    globRooms[4]->addItemToRoom(*new Item(19, "Stick", "A small rod", stickRoom));
    globRooms[4]->addItemToRoom(*new Item(20, "Stick", "Stick", stickRoom));
    globRooms[4]->addItemToRoom(*new Item(21, "Stick", "A stick that looks kinda stuck", stickRoom));
    globRooms[4]->addItemToRoom(*new Item(21, "Stick", "A stick", stickRoom));
    globRooms[4]->addItemToRoom(*new Item(23, "Stick", "A big pole", stickRoom));

    Room *lollipopRoom = globRooms[5];
    globRooms[5]->addItemToRoom(*new Item(24, "Lollipop", "A lollipop", lollipopRoom));
    globRooms[5]->addItemToRoom(*new Item(25, "Lollipop", "A yummy lollipop", lollipopRoom));
    globRooms[5]->addItemToRoom(*new Item(26, "Lollipop", "A tasty lollipop", lollipopRoom));
    globRooms[5]->addItemToRoom( *new Item(27, "Lollipop", "A HUGE spiral lolly", lollipopRoom));
    globRooms[5]->addItemToRoom(*new Item(28, "Lollipop", "A LOLlipop", lollipopRoom));
}


// Things to happen to initiate game
// - create rooms
// - fill rooms with items
// - set current room to room with id 3 (current room = globRooms[idWanted-1]) - may be unneccessary
// - create character
// - Switch character location to current room







void MainWindow::on_PlayButton_clicked()
{
    AllPages->setCurrentIndex(1);
}

void MainWindow::on_continueButton_clicked()
{
    initiateGame();
    changeRoom(2, ui->WDialogueLabel, ui->WItemsInRoom);
}

void MainWindow::on_WUpButton_clicked()
{
    if(1){
    changeRoom(3, ui->KDialogueLabel, ui->KItemsInRoom);
    } else {
        setLabelText(d.getFailedDoorAccess(), ui->WDialogueLabel);
    }
}

void MainWindow::on_KUpButton_clicked()
{
    if(1){
        changeRoom(5, ui->BDialogueLabel, ui->BItemsInRoom);
    } else {
        setLabelText(d.getFailedDoorAccess(), ui->KDialogueLabel);
    }
}


void MainWindow::on_KLeftButton_clicked()
{
    if(1){
        changeRoom(6, ui->SDialogueLabel, ui->SItemsInRoom);
    } else {
        setLabelText(d.getFailedDoorAccess(), ui->KDialogueLabel);
    }
}


void MainWindow::on_KRightButton_clicked()
{
        if(1){
        changeRoom(4, ui->KWDialogueLabel, ui->KWItemsInRoom);
    } else {
        setLabelText(d.getFailedDoorAccess(), ui->KDialogueLabel);
}
}



// for guidance - numbers = room index, letter = roomname
//                    B5
//                    \
//          S6 -- K3 -- KW4
//                    \          \
//                  W2        L7


void MainWindow::on_KWLeftButton_clicked()
{
    if(1){
    changeRoom(3, ui->KDialogueLabel, ui->KItemsInRoom);
    } else {
        setLabelText(d.getFailedDoorAccess(), ui->KWDialogueLabel);
    }
}


void MainWindow::on_KWDownButton_clicked()
{
    if(1){
        changeRoom(7, ui->LDialogueLabel, ui->LItemsInRoom);
    } else {
        setLabelText(d.getFailedDoorAccess(), ui->KWDialogueLabel);
    }
}


void MainWindow::on_BDownButton_clicked()
{
    if(1){
        changeRoom(3, ui->KDialogueLabel, ui->KItemsInRoom);
    } else {
        setLabelText(d.getFailedDoorAccess(), ui->BDialogueLabel);
    }
}


void MainWindow::on_SRightButton_clicked()
{
    if(1){
        changeRoom(3, ui->KDialogueLabel, ui->KItemsInRoom);
    } else {
        setLabelText(d.getFailedDoorAccess(), ui->SDialogueLabel);
    }
}

