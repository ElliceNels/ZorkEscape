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
    virtual string printNameAndDescription() = 0;

    string getName(){return name;};
    void setName(string name);

    string getDescription(){return description;};
    void setDescription(string description);

    //TAKE CARE OF THIS -> MEM MANAGE + DESTRUCTORS
    virtual ~Entity() {}
};

#endif // ENTITY_H
