#include <iostream>
using namespace std;
#include <string>
#include "Movie.h"

//constructor
Movie::Movie(string t, int y)
{
  title        = t;
  year         = y;
  cout<<"-- constructor Movie:  "<< title <<" ("<< year <<")"<<endl;
}

//copy constructor
Movie::Movie(const Movie& oldMovie)
{
  title        = oldMovie.title;
  year         = oldMovie.year;
  cout<<"-- copy Movie:  "<< title <<" ("<< year <<")"<<endl;
}

//destructure
Movie::~Movie()
{
  cout<<"-- destructure Movie:  "<< title <<" ("<< year <<")"<<endl;
}

void Movie::print()
{
  cout<<"*** Movie "<< title <<" ("<< year <<")"<<endl;
}

int Movie::getYear()
{
  return year;
}

string Movie::getTitle()
{
  return title;
}
