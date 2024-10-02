
#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
#include <string>
#include <ctime>
#include <chrono>
#include <thread>
#include <mutex>
#include "Book.h"
#include "PublicationRank.h"
#include "Journals.h"
#include "User.h"

using namespace std;

class Library
{
private:
    LibraryItem *libraryItems[MAX_ITEMS];
    int itemCount;
    int nextBookId;
    int totalCopies;

    User students[100]; // Assuming a maximum of 100 students
    int studentCount;
    User teachers[50]; // Assuming a maximum of 50 teachers
    int teacherCount;

public:
    // Constructor
    Library();

    // Getter functions
    int getStudentCount() const;
    int getTeacherCount() const;
    int getTotalUsers() const;
    int getTotalItems() const;

    // Library operations
    void addItem(LibraryItem *item);
    void printAllItems() const;
    Book *getBookByID(int bookID) const;
    Book *getBookByIsbn(int bookIsbn) const;

    // Search functions
    void searchBooksByAuthor(const string &bookAuthor, Book *matchingBooks[], int &matchingCount);
    void searchBooksByTitle(const string &bookAuthor, Book *matchingBooks[], int &matchingCount);
    void searchPublication(const string &bookAuthor, PublicationRank *matchingBooks[], int &matchingCount);
    void searchJournal(const string &bookAuthor, Journals *matchingBooks[], int &matchingCount);

    // User registration and management
    void registerUser(const string &name, bool isTeacher);
    void showAllRegisteredUsers();

    // Utility functions
    bool isEqualIgnoreCase(const string &str1, const string &str2);
    bool isEqualIgnore(const string &str1, const string &str2);

    // Add a new book to the library
    void addBook(int isbn, const string &author, const string &title, int originalPublicationYear);

    // Borrow and return operations
    bool borrowBook(const string &userName, int bookIdToBorrow);
    bool returnBook(Book *book);
    bool borrowPublication(const string &userName, int publication);
    bool returnPub(PublicationRank *publicationRank);
    bool borrowJournal(const string &userName, int title);

    virtual ~Library(); // Virtual destructor
};

#endif // LIBRARY_H
