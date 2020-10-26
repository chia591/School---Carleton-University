#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Date.h"
#include "Object.h"

Date::Date(int d, int m, int y)
{
  setDate(d, m, y);
}

Date::~Date() {}

void Date::setDate(int d,int m,int y)
{
  year  = ( ( y > 0) ? y : 0 );
  month = ( ( m > 0 && m <= 12) ? m : 0 );
  day   = ( ( d > 0 && d <= lastDayInMonth() ) ? d : 0 );
}

/*
void Date::printShort()
{
  cout<<setfill('0')<<setw(2)<<day<<"/"
      <<setfill('0')<<setw(2)<<month<<"/"
      <<setfill('0')<<setw(4)<<year<<endl;
}
*/

void Date::printLong()
{
  cout << "in non-const printLong() function" << endl;

  cout<<getMonthStr()<<" "<<day<<", "<<year<<endl;

//  day = 0;
}

void Date::printLong() const
{
  cout << "in const printLong() function" << endl;

  cout<<getMonthStr()<<" "<<day<<", "<<year<<endl;

//  day = 0;
}

int Date::lastDayInMonth()
{
  switch(month)
  {
    case 2:
      if (leapYear())
        return 29;
      else
        return 28;
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      return 31;
    default:
      return 30;
  }
}

bool Date::leapYear()
{
  if ( year%400 == 0 ||
       (year%4 == 0 && year%100 != 0) )
    return true;
  else
    return false;
}

string Date::getMonthStr() const
{
  string monthStrings[] = {
    "January", "Februrary", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December" };

  if ( month >= 1 && month <= 12 )
    return monthStrings[month-1];
  else
    return "Unknown";
}

ostream& operator<<(ostream& out, Date& d)
{
  out<<setfill('0')<<setw(2)<<d.day<<"/"
     <<setfill('0')<<setw(2)<<d.month<<"/"
     <<setfill('0')<<setw(4)<<d.year
     << "   (" << d.getId()<< ")" <<endl;

  return out;
}

bool operator< (const Date &d1, const Date &d2)
{
  //cout<<"Year    "<<d1.year<<"   "<<d2.year<<endl;
  if (d1.year != d2.year) { return d1.year < d2.year; }
  //cout<<"Month   "<<d1.month<<"   "<<d2.month<<endl;
  else if (d1.month != d2.month) { return d1.month < d2.month; }
  //cout<<"Day     "<<d1.day<<"   "<<d2.day<<endl;
  return d1.day < d2.day;
}

bool operator== (const Date &d1, const Date &d2)
{
  return (d1.year == d2.year) && (d1.month == d2.month) && (d1.day == d2.day);
}
