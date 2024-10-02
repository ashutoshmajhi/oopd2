
#include "PublicationRank.h"

// Constructor implementation
PublicationRank::PublicationRank(int ID, const string &publication, int rank, double totalPaid)
    : ID(ID), publication(publication), rank(rank), totalPaid(totalPaid), borrowed(false) {}

// Method implementations
int PublicationRank::getID() const
{
    return ID;
}

string PublicationRank::getPublication() const
{
    return publication;
}

int PublicationRank::getrank() const
{
    return rank;
}

double PublicationRank::gettotalPaid() const
{
    return totalPaid;
}

bool PublicationRank::isBorrowed() const
{
    return borrowed;
}

void PublicationRank::setBorrowed(bool status)
{
    borrowed = status;
}

void PublicationRank::printDetails() const
{
    cout << "ID: " << ID << "\nPublication Name: " << publication << "\nRank: " << rank << "\nTotal Paid: " << totalPaid << "\n";
}
