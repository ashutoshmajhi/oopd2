
#ifndef LIBRARYITEM_H
#define LIBRARYITEM_H

#include <iostream>
#include <string>
using namespace std;

const int MAX_ITEMS = 500; // Maximum number of items in the library

class LibraryItem
{
public:
    virtual void printDetails() const = 0;
    virtual ~LibraryItem() {}
};

#endif // LIBRARYITEM_H
