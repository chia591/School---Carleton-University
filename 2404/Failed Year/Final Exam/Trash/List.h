#ifndef LIST_H
#define LIST_H

#include <string>
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
  };

  public:
    List();
    ~List();
    List<T>& operator+=(T* x);
    void del(int y, int x);
    void print() const;

  protected:
    Node* head;
};

template <class T>
List<T>::List()
{
  head = NULL;
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
  Node* tmpNode;
  Node* currNode;
  Node* prevNode;

  tmpNode = new Node;
  tmpNode->data = x;
  tmpNode->next = NULL;

  currNode = head;
  prevNode = NULL;

  while (currNode != NULL) {
    prevNode = currNode;
    currNode = currNode->next;
  }

  if(prevNode == NULL)
  {
    head = tmpNode;
  }
  else
  {
    prevNode->next = tmpNode;
  }

  return *this;
}

template <class T>
void List<T>::del(int y, int x)
{
  Node* currNode;
  Node* prevNode;

  currNode = head;
  prevNode = NULL;

  while (currNode != NULL) {
    if ((currNode->data->getCor()[0] == y) && (currNode->data->getCor()[1] == x))
      break;

    prevNode = currNode;
    currNode = currNode->next;
  }

  if (currNode == NULL) {
    cout<<" Err: Token at location ("<<y<<","<<x<<") was not found and nothing was deleted"<<endl; 
    return;
  }

  if (prevNode == NULL)
    head = currNode->next;
  else
    prevNode->next = currNode->next;

  delete currNode;
}

template <class T>
void List<T>::print() const
{
    
}

#endif
