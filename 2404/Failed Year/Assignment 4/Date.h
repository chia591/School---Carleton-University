#ifndef DATE_H
#define DATE_H

#include "Object.h"

class Date : public Object
{
  public:
    Date(int=0, int=0, int=2000);
    ~Date();
    void setDate(int, int, int);
    //void printShort();
    void printLong();
    void printLong() const;

    friend ostream& operator<<(ostream& out, Date& d);
    friend bool operator< (const Date &d1, const Date &d2);
    friend bool operator== (const Date &d1, const Date &d2);

  private:
    int day;
    int month;
    int year;
    int  lastDayInMonth();
    bool leapYear();
    string getMonthStr() const;
};

#endif
