
#ifndef CLASSFUNCTIONS_H
#define CLASSFUNCTIONS_H

#include "Library.h"
#include <iostream>
#include <string>
#include <ctime>
#include <chrono>
#include <thread>
#include <mutex>

using namespace std;

// Declare the member functions without "Library::" prefix and without redefining the Library class
// Search functions for Library
void searchBooksByAuthor(const string &bookAuthor, Book *matchingBooks[], int &matchingCount);
void searchBooksByTitle(const string &bookAuthor, Book *matchingBooks[], int &matchingCount);
void searchPublication(const string &bookAuthor, PublicationRank *matchingBooks[], int &matchingCount);
void searchJournal(const string &bookAuthor, Journals *matchingBooks[], int &matchingCount);

// Borrow and return functions
bool borrowBook(const string &userName, int bookIdToBorrow);
bool returnBook(Book *book);
bool borrowPublication(const string &userName, int publication);
bool returnPub(PublicationRank *publicationRank);
bool borrowJournal(const string &userName, int title);

#endif // CLASSFUNCTIONS_H
