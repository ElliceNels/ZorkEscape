#ifndef ENTITY_H
#define ENTITY_H

#include <string>

using namespace std;

class Entity
{
private:
    string name;
    string description;
public:
    virtual void printNameAndDescription() = 0;

    string getName(){return name;};
    void setName(string name);

    string getDescription(){return description;};
    void setDescription(string description);
};

#endif // ENTITY_H
