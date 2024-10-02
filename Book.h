
#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>
#include "LibraryItem.h" // Including the previously created LibraryItem header

using namespace std;

class Book : public LibraryItem
{
private:
    int ID;
    int book_id;
    int isbn;
    string title;
    string authors;
    int original_publication_year;
    bool borrowed;

public:
    // Constructors
    Book();
    Book(int ID, int book_id, int isbn, const string &title, const string &authors, int original_publication_year);

    // Getter and Setter functions
    int getID() const;
    void setID(int id);

    int getBookID() const;
    void setBookID(int bookid);

    int getISBN() const;
    void setISBN(int Isbn);

    string getTitle() const;
    void setTitle(const string &newTitle);

    string getAuthors() const;
    void setAuthors(const string &newAuthor);

    int getPublicationYear() const;
    void setPublicationYear(int year);

    bool isBorrowed() const;
    void setBorrowed(bool status);

    void printDetails() const override;
};

#endif // BOOK_H
