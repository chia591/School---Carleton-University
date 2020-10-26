#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <vector>
using namespace std;
#include "Book.h"
#include "List.h"

class Logger
{
  public:
    Logger(string);
    virtual void update(Book*) = 0;
    void printLogs();

  protected:
    string name;
    List books;
};

class CheckInLogger : public Logger
{
  public:
    CheckInLogger(string="“Checked-in");
    void update(Book*);
};

class CheckOutLogger : public Logger
{
  public:
    CheckOutLogger(string="“Checked-out");
    void update(Book*);
};

#endif
