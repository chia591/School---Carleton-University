#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include "Book.h"
#include "List.h"
#include "Logger.h"

class Library
{
  public:
    ~Library();
    void subscribe(Logger*);
    void notify(Book*);
    void add(Book*);
    Book* find(int);
    void checkOut(Book*);
    void checkIn(Book*);
    void print();

  private:
    List books;
    vector<Logger*> logs;
};

#endif
