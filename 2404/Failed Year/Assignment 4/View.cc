#include <iostream>
using namespace std;
#include <string>

#include "View.h"

void View::showMenu(int& choice)
{
  cout << endl << endl;
  cout << "Select an option:"<< endl;
  cout << "  (1) Add student" << endl;
  cout << "  (2) Delete student" << endl;
  cout << "  (3) Print students" << endl;
  cout << "  (0) Exit" << endl<<endl;

  cout << "Enter your selection: ";
  cin >> choice;
  if (choice == 0)
    return;

  while (choice < 1 || choice > 3) {
    cout << "Enter your selection: ";
    cin >> choice;
  }

}

void View::printStr(string str)
{
  cout << str;
}

void View::readInt(int& n)
{
  cin >> n;
}

void View::readFloat(float& f)
{
  cin >> f;
}

void View::readStr(string& str)
{
  cin >> str;
}



