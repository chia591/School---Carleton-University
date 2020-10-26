#include <iostream>
using namespace std;
#include <string>

#include "Control.h"
#include "View.h"
#include "Student.h"
#include "Date.h"
#include "List.h"


void Control::launch()
{
  int    choice, id;
  string name, num, maj;
  float  gpa;

  //cout<<2<<endl;

  initStudents();

  //cout<<3<<endl;

  initDates();

  //cout<<4<<endl;

  while (1) {
    view.showMenu(choice);

    if (choice == 0)
      break;

    if (choice == 1) {
      view.printStr("Number: ");
      view.readStr(num);
      view.printStr("Name: ");
      view.readStr(name);
      view.printStr("Major: ");
      view.readStr(maj);
      view.printStr("GPA: ");
      view.readFloat(gpa);

      Student* tmp = new Student(num, name, maj, gpa);
      stu += tmp;

    }
    else if (choice == 2) {
      view.printStr("Id: ");
      view.readInt(id);

      stu -= id;
    }
    else if (choice == 3) {
      stu.print();
    }
  }

  stu.print();
  dat.print();
}


void Control::initStudents()
{
  //cout<<2.1<<endl;

  Student* s0 = new Student("0000", "Person0", "Program0", 5.1);
  Student* s3 = new Student("0003", "Person3", "Program3", 7.6);
  Student* s7 = new Student("0007", "Person7", "Program7", 6.1);
  //Student* s8 = new Student("0008", "Person 8", "Program 8", 5.5);
  Student* s9 = new Student("0009", "Person9", "Program9", 0.2);
  Student* s4 = new Student("0004", "Person4", "Program4", 6.8);
  Student* s5 = new Student("0005", "Person5", "Program5", 5.5);
  //cout<<2.2<<endl;
  Student* s1 = new Student("0001", "Person1", "Program1", 4.2);
  Student* s2 = new Student("0002", "Person2", "Program2", 2.0);
  Student* s6 = new Student("0006", "Person6", "Program6", 9.5);
  Student* s8 = new Student("0008", "Person8", "Program8", 5.5);
  //cout<<2.3<<endl;

  stu += s2;
  //cout<<2.4<<endl;
  stu += s5;
  //cout<<2.5<<endl;
  stu += s6;
  stu += s1;
  stu += s9;
  stu += s0;
  stu += s8;
  stu += s3;
  stu += s4;
  stu += s7;
  //cout<<2.6<<endl;
}

void Control::initDates()
{
  Date* d0 = new Date(1, 1, 2001);
  Date* d1 = new Date(2, 2, 2002);
  Date* d2 = new Date(3, 2, 2002);
  Date* d3 = new Date(1, 2, 2001);
  Date* d4 = new Date(3, 1, 2002);
  Date* d5 = new Date(1, 2, 2002);
  Date* d6 = new Date(1, 12, 2004);
  Date* d7 = new Date(1, 1, 2002);
  Date* d8 = new Date(5, 1, 2003);
  Date* d9 = new Date(1, 5, 2002);

  dat += d6;
  dat += d1;
  dat += d2;
  dat += d5;
  dat += d9;
  dat += d7;
  dat += d3;
  dat += d8;
  dat += d4;
  dat += d0;
}
