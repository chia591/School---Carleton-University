#include <iostream>
using namespace std;
#include <string>
#include "Book.h"

int Book::nextId = 1001;

Book::Book(string t, string a)
{
  id     = nextId;
  ++nextId;
  title  = t;
  author = a;
  checkedIn = true;

  cout<<"-- default ctor:  "<< id <<endl;
}

Book::Book(Book& orig)
{
  cout<<"-- copy ctor:  "<< orig.id <<endl;

  id     = orig.id;
  title  = orig.title;
  author = orig.author;
  checkedIn = orig.checkedIn;
}

Book::~Book()
{
  cout<<"-- dtor:  "<< id <<endl;
}

int Book::getNextId() { return nextId; }

int Book::getId() { return id; }

string Book::getAuthor() { return author; }

bool Book::isCheckedIn() { return checkedIn; }

void Book::checkIn()
{
  checkedIn = true;
}

void Book::checkOut()
{
  checkedIn = false;
}

void Book::print() const
{
  cout<<"** "<< title <<" by "<<author<<"("<<id<<")     [Status] Checked In: "<<checkedIn<<endl;
}

