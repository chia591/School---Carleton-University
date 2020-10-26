#ifndef LIST_H
#define LIST_H

#include <iostream>
using namespace std;

template <class T>
class List
{
  class Node
  {
    public:
      T*      data;
      Node*   next;
      Node*   prev;
  };

  public:
    List();
    ~List();
    List<T>& operator+=(T* x);
    List<T>& operator-=(const int i);
    void print() const;

  protected:
    Node* head;
    Node* tail;
};

template <class T>
List<T>::List()
{
  head = NULL;
  tail = NULL;
}

template <class T>
List<T>::~List()
{
  Node* currNode;
  Node* nextNode;

  currNode = head;

  while (currNode != NULL) {
    nextNode = currNode->next;
    delete currNode;
    currNode = nextNode;
  }
}

template <class T>
List<T>& List<T>::operator+=(T* x)
{
  //cout<<"2.3.1"<<endl;

  Node* tmpNode;
  Node* currNode;
  Node* prevNode;

  prevNode = NULL;
  tmpNode = new Node;
  tmpNode->data = x;
  //cout<<"2.3.2"<<endl;

  currNode = head;

  while (currNode != NULL) {

    //cout<<"2.3.3"<<endl;

    if (*x == *(currNode->data))
    {
      cout<<"repeated entry"<<endl;
      return *this;
    }

    if (*x < *(currNode->data))
      break;

    prevNode = currNode;
    currNode = currNode->next;
  }

  //cout<<"2.3.4"<<endl;

  if((head == NULL) && (tail == NULL))
  {
    cout<<"empty"<<endl;
    tmpNode->prev = NULL;
    tmpNode->next = NULL;
    tail = tmpNode;
    head = tmpNode;
  }
  else if (currNode == NULL)
  {
    cout<<"end"<<endl;
    tmpNode->next = NULL;
    tmpNode->prev = prevNode;
    tail = tmpNode;
    prevNode->next = tmpNode;
  }
  else if (currNode->prev == NULL)
  {
    cout<<"start"<<endl;
    tmpNode->next = currNode;
    tmpNode->prev = NULL;
    currNode->prev = tmpNode;
    head = tmpNode;
  }
  else
  {
    cout<<"Middle"<<endl;
    tmpNode->next = currNode;
    tmpNode->prev = currNode->prev;
    currNode->prev = tmpNode;
    prevNode->next = tmpNode;
  }

  //cout<<"2.3.end"<<endl;

  return *this;
}

template <class T>
List<T>& List<T>::operator-=(const int i)
{
  Node* currNode;

  currNode = head;

  while (currNode != NULL) {
    if (currNode->data->getId() == i)
    {
      break;
    }

    currNode = currNode->next;
  }

  if (currNode == NULL) {
    return *this;
  }

  if (currNode->prev == NULL)
    head = currNode->next;
  else
  {
    currNode->prev->next = currNode->next;
    currNode->next->prev = currNode->prev;
  }
  if (currNode->next == NULL)
    tail = currNode->prev;
  delete currNode;

  return *this;
}

template <class T>
void List<T>::print() const
{
  Node* start;

  cout<<"assending ---"<<endl;
  start = head;
  while (start != NULL)
  {
    cout << *(start->data) << endl;
    start = start->next;
  }

  cout<<"decending ---"<<endl;
  start = tail;
  while (start != NULL)
  {
    cout<< *(start->data) <<endl;
    start = start->prev;
  }
}

#endif
