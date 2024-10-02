
#include "User.h"

// Constructor implementations
User::User() : name(""), isTeacher(false), borrowedCount(0)
{
    for (int i = 0; i < MAX_BORROWED_BOOKS; ++i)
    {
        borrowedBooks[i] = nullptr;
        borrowedbooks[i] = nullptr;
        borrowedJournals[i] = nullptr;
        borrowedDates[i] = 0;
    }
}

User::User(const string &name, bool isTeacher) : name(name), isTeacher(isTeacher), borrowedCount(0)
{
    for (int i = 0; i < MAX_BORROWED_BOOKS; ++i)
    {
        borrowedBooks[i] = nullptr;
        borrowedbooks[i] = nullptr;
        borrowedJournals[i] = nullptr;
        borrowedDates[i] = 0;
    }
}

// Getter functions
string User::getName() const { return name; }
bool User::isTeacherUser() const { return isTeacher; }
int User::getBorrowedCount() const { return borrowedCount; }
int User::getMaxBorrowedBooks() const { return MAX_BORROWED_BOOKS; }

// Utility functions
void User::incrementBorrowedCount() { borrowedCount++; }

bool User::isBookBorrowed(Book *book) const
{
    for (int i = 0; i < MAX_BORROWED_BOOKS; ++i)
    {
        if (borrowedBooks[i] == book)
        {
            return true;
        }
    }
    return false;
}

bool User::canBorrowMoreBooks() const { return getBorrowedCount() < MAX_BORROWED_BOOKS; }

// Functions to get and set last borrow times
time_t User::getLastBorrowTime(const Book *book) const
{
    for (int i = 0; i < MAX_BORROWED_BOOKS; ++i)
    {
        if (borrowedBooks[i] == book)
        {
            return borrowedDates[i];
        }
    }
    return 0; // Return 0 if the book is not found in the user's borrowed books
}

void User::setLastBorrowTime(const Book *book, time_t borrowTime)
{
    for (int i = 0; i < MAX_BORROWED_BOOKS; ++i)
    {
        if (borrowedBooks[i] == book)
        {
            borrowedDates[i] = borrowTime;
            return; // Book found and last borrow time updated
        }
    }
}

time_t User::getLastBorrowPubTime(const PublicationRank *publicationRank) const
{
    for (int i = 0; i < MAX_BORROWED_BOOKS; ++i)
    {
        if (borrowedbooks[i] == publicationRank)
        {
            return borrowedDates[i];
        }
    }
    return 0; // Return 0 if the publication is not found in the user's borrowed books
}

void User::setLastBorrowPubTime(const PublicationRank *publicationRank, time_t borrowTime)
{
    for (int i = 0; i < MAX_BORROWED_BOOKS; ++i)
    {
        if (borrowedbooks[i] == publicationRank)
        {
            borrowedDates[i] = borrowTime;
            return; // Publication found and last borrow time updated
        }
    }
}
