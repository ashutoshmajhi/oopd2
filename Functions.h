
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <string>
#include <sstream>
#include <cctype>

using namespace std;

// Function declarations
bool isNumeric(const string &str);
void splitCSVLine(const string &line, string fields[], int fieldCount);
void splitLine(const string &line, string fields[], int fieldCount);
void splitString(const string &input, string fields[], int fieldCount);
bool isValidUserName(const string &userName);
string getField(const string &line, int fieldIndex);

#endif // FUNCTIONS_H
