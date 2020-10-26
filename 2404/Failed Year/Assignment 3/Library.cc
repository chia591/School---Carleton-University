#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Library.h"


Library::~Library()
{
    for(int i = 0; i < logs.size(); i++){
        logs[i]->printLogs();
        delete logs[i];
    }
    books.cleanup();
}

void Library::subscribe(Logger* logger)
{
    logs.push_back(logger);
}

void Library::notify(Book* b)
{
    //cout<<"logs size:"<<logs.size()<<endl;
    for(int i = 0; i < logs.size(); i++)
    {
        //cout<<"1.2.i:"<<i<<endl;
        logs[i]->update(b);
    }
    //cout<<"1.2.f"<<endl;
}

void Library::add(Book* b)
{
    //cout<<"1.1"<<endl;
    books.add(b);
    //cout<<"1.2"<<endl;
    notify(b);
    //cout<<"1.3"<<endl;
}

Book* Library::find(int id)
{
    books.find(id);
}

void Library::checkOut(Book* b)
{
    b->checkOut();
    notify(b);
}

void Library::checkIn(Book* b)
{
    b->checkIn();
    notify(b);
}

void Library::print()
{
    books.print();
}