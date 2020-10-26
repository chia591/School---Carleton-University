#ifndef BOOK_H
#define BOOK_H

class Book
{
  public:
    Book(string="", string="");
    Book(Book&);
    ~Book();
    void print() const;
    static int getNextId();
    int getId();
    string getAuthor();
    bool isCheckedIn();
    void checkIn();
    void checkOut();

  private:
    static int nextId;
    int id;
    string title;
    string author;
    bool checkedIn;
};

#endif
