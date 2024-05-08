#ifndef ITEM_H
#define ITEM_H

#include <string>

using namespace std;
class Item
{
private:
    string name;
    int id;

public:
    Item (int id, string name);

    void setName();
    string getName();

    int getId();
    void setId(int id);
};

#endif // ITEM_H
