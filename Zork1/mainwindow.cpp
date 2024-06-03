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

void MainWindow::addToItemToInventory(Item item){
    mainCharacter.addToInventory(item);
    ui->listWidget->addItem(QString::fromStdString(item.getName()));
    //add the text or sum to ui
}
void useItem();//////////////////////////////////////////////////////////////////////////////////

void MainWindow::roomCreation(){

    // 6 rooms total
    Room *waitRoom, *keyRoom, *keycardRoom, *buttonRoom, *stickRoom, *lollipopRoom;

    waitRoom = new Room(2, "Waiting Room", "You are dropping in a room that has nothing.");
    keyRoom = new Room(3, "Key Room", "Oooo, this room has a LOT of keys");
    keycardRoom = new Room(4, "KeyCard Room", "Uh oh, this room is loaded with keycards too");
    buttonRoom = new Room(5, "Button Room", "There are buttons to pick up everywhere");
    stickRoom = new Room(6, "Stick Room", "Sticks Sticks Sticks");
    lollipopRoom = new Room(7, "Lollipop Room", "Wow! You made it to the lollipop room and are released by the two men!!");
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

     globRooms[1]->addItemToRoom(*new Item(1, "Key", "An old rustic key"));
     globRooms[1]->addItemToRoom(*new Item(2, "Key", "The key to a door of some sort"));
     globRooms[1]->addItemToRoom(*new Item(3, "Key", "A key with unknown use"));
     globRooms[1]->addItemToRoom(*new Item(4, "Key", "This key does nothing"));
     globRooms[1]->addItemToRoom(*new Item(5, "Key", "A key with an inscription, '9274'"));
     globRooms[1]->addItemToRoom(*new Item(6, "Key", "unknown"));
     globRooms[1]->addItemToRoom(*new Item(7, "Key", "A very dirty key"));
     globRooms[1]->addItemToRoom(*new Item(8, "Key", "Key to a lock"));

   globRooms[2]->addItemToRoom(*new Item(9, "Key-Card", "A key-card with no barcode"));
    globRooms[2]->addItemToRoom(*new Item(10, "Key-Card", "Wait this is a piece of paper"));
     globRooms[2]->addItemToRoom( *new Item(11, "Key-Card", "A key-card"));
    globRooms[2]->addItemToRoom(*new Item(12, "Key-Card", "A high-tech card with all access"));
     globRooms[2]->addItemToRoom(*new Item(13, "Key-Card", "A key-card in the shape of a key"));

     globRooms[3]->addItemToRoom(*new Item(14, "Button", "A flat button"));
    globRooms[3]->addItemToRoom(*new Item(15, "Button", "A pressy thingy"));
     globRooms[3]->addItemToRoom(*new Item(16, "Button", "Boopy boopy"));
    globRooms[3]->addItemToRoom(*new Item(17, "Button", "A button that is very red"));
    globRooms[3]->addItemToRoom(*new Item(18, "Button", "A pressible button"));

    globRooms[4]->addItemToRoom(*new Item(19, "Stick", "A small rod"));
    globRooms[4]->addItemToRoom(*new Item(20, "Stick", "Stick"));
    globRooms[4]->addItemToRoom(*new Item(21, "Stick", "A stick that looks kinda stuck"));
    globRooms[4]->addItemToRoom(*new Item(21, "Stick", "A stick"));
    globRooms[4]->addItemToRoom(*new Item(23, "Stick", "A big pole"));

    globRooms[5]->addItemToRoom(*new Item(24, "Lollipop", "A lollipop"));
    globRooms[5]->addItemToRoom(*new Item(25, "Lollipop", "A yummy lollipop"));
    globRooms[5]->addItemToRoom(*new Item(26, "Lollipop", "A tasty lollipop"));
    globRooms[5]->addItemToRoom( *new Item(27, "Lollipop", "A HUGE spiral lolly"));
    globRooms[5]->addItemToRoom(*new Item(28, "Lollipop", "A LOLlipop"));
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
    addToItemToInventory(*new Item(3, "Key", "A key with unknown use"));
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

