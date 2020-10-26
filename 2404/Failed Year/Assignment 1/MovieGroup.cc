#include <iostream>
using namespace std;
#include <string>
#include "MovieGroup.h"

//constructor
MovieGroup::MovieGroup(int c)
{
  count = c;
}

//copy constructor
MovieGroup::MovieGroup(const MovieGroup& oldMovieGroup)
{
  count = oldMovieGroup.count;
  for(int i = 0; i < count; i++)
  {
    movies[i] = new Movie(*oldMovieGroup.movies[i]);
  }
}

//destructure
MovieGroup::~MovieGroup()
{
  for(int i = 0; i < count; i++)
  {
    delete movies[i];
  }
}

void MovieGroup::print()
{
  for(int i = 0; i < count; i++)
  {
    movies[i]->print();
  }
}

void MovieGroup::add(Movie* m)
{
  if(count > MAX_AMMOUNT)
  {
    cout << " -- Error -- Too many movies to be added (action not executed)" << endl;
  }
  else
  {
    /* for loops do not work for some reason
    count++;
    for(int i = count - 1; i > -1; i--)
    {
      if(m->getYear() < movies[i]->getYear())
      {
        movies[i] = movies[i - 1];
        movies[i - 1] = m;
        break;
      }
      else
      {
        movies[i] = movies[i - 1];
      }
    }
    */
    
    int i = count - 1;
    while(i >= 0 && m->getYear() < movies[i]->getYear())
    {
      movies[i + 1] = movies[i];
      i--;
    }
    movies[i + 1] = m;
    count++;
  }
}

void MovieGroup::merge(MovieGroup& mg)
{
  if(count + mg.count > MAX_AMMOUNT)
  {
    cout << " -- Error -- Too many movies to be added (action not executed)" << endl;
  }
  else
  {
    for(int i = 0; i < mg.count; i++)
    {
      add(new Movie(*mg.movies[i]));
    }
  }
}
