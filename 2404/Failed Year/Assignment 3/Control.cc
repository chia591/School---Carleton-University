#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Control.h"

Control::Control()
{
  cil = new CheckInLogger;
  col = new CheckOutLogger;
  library.subscribe(cil);
  library.subscribe(col);
}

void Control::launch()
{
  int bookId;
  int choice;
  Book* bok;

  initBooks();

  while (1) {
    view.showMenu(choice);

    if (choice == 0) 
      break;

    view.printStr("Book id: ");
    view.readInt(bookId);
    bok = library.find(bookId);
    if (bok == NULL)
    {
      cout<<"there is no books found with that id"<<endl<<endl;
    }
    else
    {
      if (choice == 1)
      {
        if(bok->isCheckedIn() == true)
        {
          library.checkOut(bok);
          cout<<" Book has been checked out"<<endl;
        }
        else
        {
          cout<<" Book is already checked out"<<endl;
        }
        
      }
      else if (choice == 2)
      {
        if(bok->isCheckedIn() == false)
        {
        library.checkIn(bok);
        cout<<" Book has been checked in"<<endl;
        }
        else
        {
          cout<<" Book is already checked in"<<endl;
        }
        
      }
    }

  }
  library.print();
}

void Control::initBooks()
{
  Book* b;
  //cout<<"ok"<<endl;
  b = new Book("Ender's Game", "Card, Orson Scott");
  //cout<<"1"<<endl;
  library.add(b);
  //cout<<"2"<<endl;
  b = new Book("Dune", "Herbert, Frank");
  library.add(b);
  b = new Book("Foundation", "Asimov, Isaac");
  library.add(b);
  b = new Book("Hitch Hiker's Guide to the Galaxy", "Adams, Douglas");
  library.add(b);
  b = new Book("1984", "Orwell, George");
  library.add(b);
  b = new Book("Stranger in a Strange Land", "Heinlein, Robert A.");
  library.add(b);
  b = new Book("Farenheit 451", "Bradbury, Ray");
  library.add(b);
  b = new Book("2001:  A Space Odyssey", "Clarke, Arthur C.");
  library.add(b);
  b = new Book("I, Robot", "Asimov, Isaac");
  library.add(b);
  b = new Book("Starship Troopers", "Heinlein, Robert A.");
  library.add(b);
  b = new Book("Do Androids Dream of Electric Sheep?", "Dick, Philip K.");
  library.add(b);
  b = new Book("Neuromancer", "Gibson, William");
  library.add(b);
  b = new Book("Ringworld", "Niven, Larry");
  library.add(b);
  b = new Book("Rendezvous with Rama", "Clarke, Arthur C.");
  library.add(b);
  b = new Book("Hyperion", "Simmons, Dan");
  library.add(b);
}

