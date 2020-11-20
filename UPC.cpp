#include "UPC.h"
using namespace std;

/*
Name: UPC.cpp
Author: Kyle White
Date: 11/20/2020
Description: UPC.cpp implements all prototypes defined in the UPC.h header file.
*/

// Default constructor initializes the code to 0 and product description to an empty string.
UPC::UPC() {
    code = 0;
    product = "";
}

// Copy constructor creates a deep copy of the parameter UPC object.
UPC::UPC(const UPC &other) {
    this->code = other.code;
    this->product = other.product;
}

// Assignment constructor.
UPC &UPC::operator=(const UPC &other) {
    this->code = other.code;
    this->product = other.product;
    return *this;
}

// Overloaded constructor accepts a long long parameter and creates a UPC object
// with an empty product description (for searching purposes).
UPC::UPC(long long code) {
    this->code = code;
    this->product = "";
}

// Overloaded constructor accepts a long long and string as parameters and constructs
// a UPC object.
UPC::UPC(long long code, string itemName) {
    this->code = code;
    this->product = itemName;
}

// Destructor
UPC::~UPC() {
}

// Accessor for the code field.
long long UPC::getCode() {
    return this->code;
}

// Accessor for the product field.
string UPC::getDescription() {
    return this->product;
}

// Overloaded > operator which returns true if this > other.
bool &UPC::operator>(const UPC &other) {
    bool check = this->code > other.code;
    bool *pCheck = &check;
    return *pCheck;
}

// Overloaded < operator which returns true if this < other.
bool &UPC::operator<(const UPC &other) {
    bool check = this->code < other.code;
    bool *pCheck = &check;
    return *pCheck;
}

// Overloaded == operator which returns true if this->code == other.code,
// does not check product description to prevent excessive modification to BST class.
bool &UPC::operator==(const UPC &other) {
    bool check = this->code == other.code;
    bool *pCheck = &check;
    return *pCheck;
}

