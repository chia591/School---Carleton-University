#ifndef OBJECT_H
#define OBJECT_H

#include <iostream>
#include <string>

class Object
{
    public:
        Object();
        int getId();

    private:
        int id;
        static int nextId;

};

#endif