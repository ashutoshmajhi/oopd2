#include "Book.h"

// Constructor implementations
Book::Book() : book_id(0), isbn(0), title(""), authors(""), original_publication_year(0), borrowed(false) {}

Book::Book(int ID, int book_id, int isbn, const string &title, const string &authors, int original_publication_year)
    : ID(ID), book_id(book_id), isbn(isbn), title(title), authors(authors), original_publication_year(original_publication_year), borrowed(false) {}

// Method implementations
int Book::getID() const { return ID; }
void Book::setID(int id) { ID = id; }

int Book::getBookID() const { return book_id; }
void Book::setBookID(int bookid) { book_id = bookid; }

int Book::getISBN() const { return isbn; }
void Book::setISBN(int Isbn) { isbn = Isbn; }

string Book::getTitle() const { return title; }
void Book::setTitle(const string &newTitle) { title = newTitle; }

string Book::getAuthors() const { return authors; }
void Book::setAuthors(const string &newAuthor) { authors = newAuthor; }

int Book::getPublicationYear() const { return original_publication_year; }
void Book::setPublicationYear(int year) { original_publication_year = year; }

bool Book::isBorrowed() const { return borrowed; }
void Book::setBorrowed(bool status) { borrowed = status; }

void Book::printDetails() const
{
    cout << "ID: " << ID << "\nBook_id: " << book_id << "\nISBN: " << isbn << "\nTitle: " << title << "\nAuthors: " << authors << "\nPublication Year: " << original_publication_year << "\n";
}
