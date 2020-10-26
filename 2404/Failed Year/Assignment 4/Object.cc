#include <iostream>
using namespace std;
#include <string>

#include "Object.h"

int Object::nextId = 0;

Object::Object()
{
    id = nextId;
    nextId++;
}

int Object::getId()
{
    return id;
}
