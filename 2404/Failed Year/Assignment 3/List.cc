#include <iostream>
using namespace std;

#include "List.h"

List::List()
{
  head = NULL;
}

List::~List()
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

void List::add(Book* bok)
{
  //cout<<"adding -->";
  Node* tmpNode;
  Node* currNode;
  Node* prevNode;

  tmpNode = new Node;
  tmpNode->data = bok;
  tmpNode->next = NULL;

  currNode = head;
  prevNode = NULL;

  while (currNode != NULL) {
    if (bok->getAuthor() == currNode->data->getAuthor() && bok->getId() == currNode->data->getId())
    {
      delete tmpNode;
      cout<<"Book is already in the system"<<endl;
      return;
    }
    if (bok->getAuthor() < currNode->data->getAuthor())
      break;

    prevNode = currNode;
    currNode = currNode->next;
  }

  if (prevNode == NULL)
    head = tmpNode;
  else
    prevNode->next = tmpNode;

  tmpNode->next  = currNode;

  //cout<<"<-- Done"<<endl;
}

void List::del(int id)
{
  cout<<"Deleting -->";
  Node* currNode;
  Node* prevNode;

  currNode = head;
  prevNode = NULL;

  while (currNode != NULL) {
    if (currNode->data->getId() == id)
      break;

    prevNode = currNode;
    currNode = currNode->next;
  }

// when do we get here?  2 cases:  we found the data, or we didn't

  if (prevNode == NULL)
    head = currNode->next;
  else
    prevNode->next = currNode->next;

  delete currNode; 

  cout<<"<-- done"<<endl;
}

Book* List::find(int id)
{
  Node* currNode;
  Node* prevNode;

  if (head == NULL)
    return NULL;

  currNode = head;
  prevNode = NULL;
  
  while (currNode != NULL) {
    if (currNode->data->getId() == id)
      return currNode->data;

    prevNode = currNode;
    currNode = currNode->next;
  }
  return NULL;

}

void List::cleanup()
{
  Node* currNode;
  Node* nextNode;

  currNode = head;

  while (currNode != NULL) {
    nextNode = currNode->next;
    delete currNode->data;
    currNode = nextNode;
  }
}

void List::print() const
{
  Node* currNode = head;

  while (currNode != NULL) {
    currNode->data->print();
    currNode = currNode->next;
  }
}

