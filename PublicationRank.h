
#ifndef PUBLICATIONRANK_H
#define PUBLICATIONRANK_H

#include <iostream>
#include <string>
#include "LibraryItem.h"
using namespace std;

class PublicationRank : public LibraryItem
{
private:
    int ID;
    string publication;
    int rank;
    double totalPaid;
    bool borrowed;

public:
    // Constructor
    PublicationRank(int ID, const string &publication, int rank, double totalPaid);

    int getID() const;
    string getPublication() const;
    int getrank() const;
    double gettotalPaid() const;
    bool isBorrowed() const;
    void setBorrowed(bool status);
    void printDetails() const override;
};

#endif // PUBLICATIONRANK_H
