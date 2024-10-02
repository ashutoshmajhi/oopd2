#include "Journals.h"

// Constructor implementation
Journals::Journals(int ID, const string &title)
    : ID(ID), title(title) {}

// Method implementations
int Journals::getID() const
{
    return ID;
}

string Journals::getTitle() const
{
    return title;
}

void Journals::printDetails() const
{
    cout << "ID: " << ID << "\nJournal Title: " << title << "\n";
}
