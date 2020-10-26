#ifndef STUDENT_H
#define STUDENT_H

#include <string>

#include "Object.h"

class Student : public Object
{
  public:
    Student(string="000000000", string="Hey you!", string="basket-weaving", float=0.0f);
    string getName() const;
    void setName(string n);

    friend ostream& operator<< (ostream& out, Student& s);
    friend bool operator< (const Student &s1, const Student &s2);
    friend bool operator== (const Student &s1, const Student &s2);

  private:
    const string number;
    string name;
    string majorPgm;
    float  gpa;
};

#endif
