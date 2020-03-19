#ifndef MOVIE_H
#define MOVIE_H

class Movie
{
  public:
    Movie(string t, int y);
    Movie(const Movie&);
    ~Movie();
    void print();
    int getYear();
    string getTitle();

  private:
    string title;
    int    year;
};

#endif
