#include <iostream>
#include <iomanip>
using namespace std;
#include <string>

#include "Student.h"
#include "Object.h"


Student::Student(string s1, string s2, string s3, float g)
  : number(s1), name(s2), majorPgm(s3), gpa(g) { }

string Student::getName() const { return name; }
void Student::setName(string n) { name = n; }

ostream& operator<<(ostream& out, Student& s)
{
  out << "Student:  " << s.number << "  " << left << setw(10) << s.name << " "
                      << setw(15) << s.majorPgm << "   GPA: "
                      << fixed << setprecision(2) << setw(5) << right << s.gpa
                      << "   (" << s.getId()<< ")" << endl;
  return out;
}

bool operator< (const Student &s1, const Student &s2)
{
  return s1.name < s2.name;
}

bool operator== (const Student &s1, const Student &s2)
{
  return (s1.name == s2.name) && (s1.number == s2.number);
}
