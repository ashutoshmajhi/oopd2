
#ifndef JOURNALS_H
#define JOURNALS_H

#include <iostream>
#include <string>
#include "LibraryItem.h"

using namespace std;

class Journals : public LibraryItem
{
private:
    int ID;
    string title;

public:
    // Constructor
    Journals(int ID, const string &title);

    int getID() const;
    string getTitle() const;
    void printDetails() const override;
};

#endif // JOURNALS_H
