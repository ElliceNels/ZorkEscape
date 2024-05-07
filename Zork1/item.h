#ifndef ITEM_H
#define ITEM_H

#include <string>

using namespace std;
class Item
{
private:
    string description;
    int id;

public:
    Item (string description);

    void setDescription();
    string getDescription();

    int getId();
    void setId(int id);
};

#endif // ITEM_H
