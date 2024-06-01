#include <iostream>

using namespace std;
#include "ZorkUL.h"
#include "MainWindow.h"
#include <QApplication>
#include <QtWidgets>

using namespace Qt::StringLiterals;


int main(int argc, char* argv[]) {



    QApplication app(argc, argv);


    auto locale = QLocale::system();

    QTranslator translator;
    if (translator.load(locale, u"arrowpad"_s, u"_"_s))
        app.installTranslator(&translator);

    ZorkUL temp;
    temp.play();
    // MainWindow mainWindow;
    // mainWindow.show();


    return 0;
    // return app.exec();

}

ZorkUL::ZorkUL() {
    createRooms();
}

void ZorkUL::createRooms()  {

    // 11 rooms total
    Room *waitRoom, *doorRoom, *nRoom1, *nRoom2, *keyRoom, *NRoom, *LRoom, *nRoom, *rRoom, *cRoom, *qRoom;

    waitRoom = new Room("Waiting Room");
    doorRoom = new Room("Doors Room");
    doorRoom->addItem(new Item("key", 3, 33));
    nRoom1 = new Room("placeholder");
    nRoom2 = new Room("placeholder");
    keyRoom = new Room("Key Room");
    doorRoom->addItem(new Item("key", 3, 33));
    doorRoom->addItem(new Item("key", 3, 33));
    doorRoom->addItem(new Item("key", 3, 33));
    doorRoom->addItem(new Item("key", 3, 33));
    doorRoom->addItem(new Item("key", 3, 33));
    doorRoom->addItem(new Item("key", 3, 33));
    NRoom = new Room("NRoom");
    nRoom = new Room("nRoom");
    LRoom = new Room("LRoom");
    cRoom = new Room("cRoom");
    rRoom = new Room("rRoom");
    qRoom = new Room("Exit Room");


    //             (N, E, S, W)
    waitRoom->setExits(doorRoom, NULL, NULL, NULL);
    doorRoom->setExits(nRoom1, keyRoom, NULL, nRoom2);
    keyRoom->setExits(NRoom, NULL, LRoom, doorRoom);
    LRoom->setExits(keyRoom, cRoom, NULL, NULL);
    NRoom->setExits(NULL, nRoom, keyRoom, NULL);
    nRoom->setExits(NULL, NULL, cRoom, NRoom);
    cRoom->setExits(nRoom, NULL, rRoom, LRoom);
    rRoom->setExits(cRoom, NULL, NULL, qRoom);

    currentRoom = waitRoom;
}

/**
 *  Main play routine.  Loops until end of play.
 */
void ZorkUL::play() {
    printWelcome();

    // Enter the main command loop.  Here we repeatedly read commands and
    // execute them until the ZorkUL game is over.

    bool finished = false;
    while (!finished) {
        // Create pointer to command and give it a command.
        Command* command = parser.getCommand();
        // Pass dereferenced command and check for end of game.
        finished = processCommand(*command);
        // Free the memory allocated by "parser.getCommand()"
        //   with ("return new Command(...)")
        delete command;
    }
    cout << endl;
    cout << "end" << endl;
}

void ZorkUL::printWelcome() {
    cout << "start"<< endl;
    cout << "info for help"<< endl;
    cout << endl;
    cout << currentRoom->longDescription() << endl;
}

/**
 * Given a command, process (that is: execute) the command.
 * If this command ends the ZorkUL game, true is returned, otherwise false is
 * returned.
 */
bool ZorkUL::processCommand(Command command) {
    if (command.isUnknown()) {
        cout << "invalid input"<< endl;
        return false;
    }

    string commandWord = command.getCommandWord();
    if (commandWord.compare("info") == 0)
        printHelp();

    else if (commandWord.compare("map") == 0)
    {
        cout << "        [n]     [N] --- [n]" << endl;
        cout << "         |       |       | " << endl;
        cout << "         |       |       | " << endl;
        cout << "[n] --- [k] --- [k]      | " << endl;
        cout << "         |       |       | " << endl;
        cout << "         |       |       | " << endl;
        cout << "        [w]     [l] --- [c]" << endl;
        cout << "                         | " << endl;
        cout << "                [q] --- [r]" << endl;

    }

    else if (commandWord.compare("go") == 0)
        goRoom(command);

    else if (commandWord.compare("take") == 0)
    {
        if (!command.hasSecondWord()) {
            cout << "incomplete input"<< endl;
        }
        else
            if (command.hasSecondWord()) {
                cout << "you're trying to take " + command.getSecondWord() << endl;
                int location = currentRoom->isItemInRoom(command.getSecondWord());
                if (location  < 0 )
                    cout << "item is not in room" << endl;
                else
                    cout << "item is in room" << endl;
                cout << "index number " << + location << endl;
                cout << endl;
                cout << currentRoom->longDescription() << endl;
            }
    }

    else if (commandWord.compare("put") == 0)
    {

    }
    /*
    {
    if (!command.hasSecondWord()) {
        cout << "incomplete input"<< endl;
        }
        else
            if (command.hasSecondWord()) {
            cout << "you're adding " + command.getSecondWord() << endl;
            itemsInRoom.push_Back;
        }
    }
*/
    else if (commandWord.compare("quit") == 0) {
        if (command.hasSecondWord())
            cout << "overdefined input"<< endl;
        else
            return true; /**signal to quit*/
    }
    return false;
}
/** COMMANDS **/
void ZorkUL::printHelp() {
    cout << "valid inputs are; " << endl;
    parser.showCommands();

}

void ZorkUL::goRoom(Command command) {
    if (!command.hasSecondWord()) {
        cout << "incomplete input"<< endl;
        return;
    }

    string direction = command.getSecondWord();

    // Try to leave current room.
    Room* nextRoom = currentRoom->nextRoom(direction);

    if (nextRoom == NULL)
        cout << "underdefined input"<< endl;
    else {
        currentRoom = nextRoom;
        cout << currentRoom->longDescription() << endl;
    }
}

string ZorkUL::go(string direction) {
    //Make the direction lowercase
    //transform(direction.begin(), direction.end(), direction.begin(),:: tolower);
    //Move to the next room
    Room* nextRoom = currentRoom->nextRoom(direction);
    if (nextRoom == NULL)
        return("direction null");
    else
    {
        currentRoom = nextRoom;
        return currentRoom->longDescription();
    }
}
