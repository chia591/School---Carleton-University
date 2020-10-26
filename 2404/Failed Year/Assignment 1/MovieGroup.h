#ifndef MOVIEGROUP_H
#define MOVIEGROUP_H

#include "Movie.h"

#define MAX_AMMOUNT 64

class MovieGroup
{
  public:
    MovieGroup(int c);
    MovieGroup(const MovieGroup&);
    ~MovieGroup();
    void print();
    void add(Movie*);
    void merge(MovieGroup&);

  private:
    Movie* movies[MAX_AMMOUNT];
    int    count;
};

#endif
