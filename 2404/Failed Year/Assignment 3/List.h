#ifndef LIST_H
#define LIST_H

#include "Book.h"

class List
{
  class Node
  {
/*
    friend class List;
    private:
*/
    public:
      Book* data;
      Node* next;
  };

  public:
    List();
    ~List();
    void add(Book*);
    void del(int);
    void print() const;
    Book* find(int);
    void cleanup();

  private:
    Node* head;
};

#endif
