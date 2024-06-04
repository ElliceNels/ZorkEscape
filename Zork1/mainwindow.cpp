#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "room.h"
#include "item.h"
extern Room *globRooms[6];

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
     connect(ui->KEY1, &QPushButton::clicked, [this]() { handleKeyClick(1, 1, ui->KEY1); });
     connect(ui->LEFTKEY2, &QPushButton::clicked, [this]() { handleKeyClick(1, 2, ui->LEFTKEY2); });
     connect(ui->KEY7, &QPushButton::clicked, [this]() { handleKeyClick(1, 7, ui->KEY7); });
     connect(ui->KEY8, &QPushButton::clicked, [this]() { handleKeyClick(1, 8, ui->KEY8); });
     connect(ui->KEY5, &QPushButton::clicked, [this]() { handleKeyClick(1, 5, ui->KEY5); });
     connect(ui->KEY3, &QPushButton::clicked, [this]() { handleKeyClick(1, 3, ui->KEY3); });
     connect(ui->UPKEY4, &QPushButton::clicked, [this]() { handleKeyClick(1, 4, ui->UPKEY4); });
     connect(ui->RIGHTKEY6, &QPushButton::clicked, [this]() { handleKeyClick(1, 6, ui->RIGHTKEY6); });

     connect(ui->STICK19, &QPushButton::clicked, [this]() { handleKeyClick(4, 19, ui->STICK19); });
     connect(ui->STICK20, &QPushButton::clicked, [this]() { handleKeyClick(4, 20, ui->STICK20); });
     connect(ui->STICK21, &QPushButton::clicked, [this]() { handleKeyClick(4, 21, ui->STICK21); });
     connect(ui->STICK22, &QPushButton::clicked, [this]() { handleKeyClick(4, 22, ui->STICK22); });
     connect(ui->STICK23, &QPushButton::clicked, [this]() { handleKeyClick(4, 23, ui->STICK23); });

     connect(ui->BUTTON14, &QPushButton::clicked, [this]() { handleKeyClick(3, 14, ui->BUTTON14); });
     connect(ui->BUTTON15, &QPushButton::clicked, [this]() { handleKeyClick(3, 15, ui->BUTTON15); });
     connect(ui->BUTTON16, &QPushButton::clicked, [this]() { handleKeyClick(3, 16, ui->BUTTON16); });
     connect(ui->BUTTON17, &QPushButton::clicked, [this]() { handleKeyClick(3, 17, ui->BUTTON17); });
     connect(ui->BUTTON18, &QPushButton::clicked, [this]() { handleKeyClick(3, 18, ui->BUTTON18); });

     connect(ui->KEYCARD9, &QPushButton::clicked, [this]() { handleKeyClick(2, 9, ui->KEYCARD9); });
     connect(ui->KEYCARD10, &QPushButton::clicked, [this]() { handleKeyClick(2, 10, ui->KEYCARD10); });
     connect(ui->KEYCARD11, &QPushButton::clicked, [this]() { handleKeyClick(2, 11, ui->KEYCARD11); });
     connect(ui->KEYCARD12, &QPushButton::clicked, [this]() { handleKeyClick(2, 12, ui->KEYCARD12); });
     connect(ui->KEYCARD13, &QPushButton::clicked, [this]() { handleKeyClick(2, 13, ui->KEYCARD13); });

    AllPages = ui->AllPages;
    AllPages->setCurrentIndex(0);
    ui->listWidget->hide();

}

// DESTRUCTOR
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initiateGame(){
    roomCreation();
    itemCreation();
    ui->listWidget->show();

}

void MainWindow::handleKeyClick(int room, int itemId, QPushButton* button) {
    Item item = globRooms[room]->findItemWithId(itemId);
    button->hide();
    addToItemToInventory(item);
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
    ui->listWidget->addItem(QString::fromStdString(item.getName() +" "+ to_string(item.getId())));
}

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

//MEM MANAGE -> ALL ON HEAP
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
    globRooms[4]->addItemToRoom(*new Item(22, "Stick", "A stick"));
    globRooms[4]->addItemToRoom(*new Item(23, "Stick", "A big pole"));

    globRooms[5]->addItemToRoom(*new Item(24, "Lollipop", "A lollipop"));
    globRooms[5]->addItemToRoom(*new Item(25, "Lollipop", "A yummy lollipop"));
    globRooms[5]->addItemToRoom(*new Item(26, "Lollipop", "A tasty lollipop"));
    globRooms[5]->addItemToRoom( *new Item(27, "Lollipop", "A HUGE spiral lolly"));
    globRooms[5]->addItemToRoom(*new Item(28, "Lollipop", "A LOLlipop"));
}

// ----------------------------------------------------------
// for guidance - numbers = room index, letter = roomname
//                    B5
//                    \
//          S6 -- K3 -- KW4
//                    \          \
//                  W2        L7

void MainWindow::on_PlayButton_clicked()
{
    AllPages->setCurrentIndex(1);
}

void MainWindow::on_continueButton_clicked()
{
    initiateGame();
    changeRoom(2, ui->WDialogueLabel, ui->WItemsInRoom);
    ui->listWidget->show();
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
    if(mainCharacter.isInInventory(9) || mainCharacter.isInInventory(11) ){
        changeRoom(5, ui->BDialogueLabel, ui->BItemsInRoom);
    } else {
        setLabelText(d.getFailedDoorAccess(), ui->KDialogueLabel);
    }
}

void MainWindow::on_KLeftButton_clicked()
{
    if(mainCharacter.isInInventory(2) || mainCharacter.isInInventory(11)){
        changeRoom(6, ui->SDialogueLabel, ui->SItemsInRoom);
    } else {
        setLabelText(d.getFailedDoorAccess(), ui->KDialogueLabel);
    }
}

void MainWindow::on_KRightButton_clicked()
{
        if(mainCharacter.isInInventory(23) || mainCharacter.isInInventory(11)){
        changeRoom(4, ui->KWDialogueLabel, ui->KWItemsInRoom);
    } else {
        setLabelText(d.getFailedDoorAccess(), ui->KDialogueLabel);
}
}

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
    if(mainCharacter.isInInventory(17)|| mainCharacter.isInInventory(11)){
        changeRoom(7, ui->LDialogueLabel, ui->LItemsInRoom);
        setLabelText(d.getVictory(), ui->LDialogueLabel);
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

void MainWindow::on_CLOSELOLLIPOP_clicked()
{
    close();
}

