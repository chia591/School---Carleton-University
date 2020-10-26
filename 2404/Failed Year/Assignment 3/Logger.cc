#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;

#include "Logger.h"
#include "Book.h"
#include "List.h"

Logger::Logger(string n)
{
    name = n;
}

void Logger::printLogs()
{
    cout<<endl<<"-----------"<<name<<endl;
    books.print();
}

CheckInLogger::CheckInLogger(string n) : Logger(n) {}

void CheckInLogger::update(Book* b)
{
    //cout<<"1.2. .checkIn"<<endl;
    if(b->isCheckedIn() == true)
    {
        books.add(b);
    }
    else
    {
        books.del(b->getId());
    }
}

CheckOutLogger::CheckOutLogger(string n) : Logger(n) {}

void CheckOutLogger::update(Book* b)
{
    //cout<<"1.2. .checkOut"<<endl;
    if(b->isCheckedIn() == false)
    {
        //cout<<"add"<<endl;
        books.add(b);
    }
    else
    {
        //cout<<"del"<<endl;
        //cout<<"getting id:"<<b->getId()<<endl;
        //books.print();
        //cout<<"print Passed"<<endl;
        //books.del(b->getId());
    }
}