#include <string>
using namespace std;

/*
Name: UPC.h
Author: Kyle White
Date: 11/20/2020
Description: Header file for the UPC class which defines
the private members and public methods of the UPC class. UPC
objects store a long long integer code and a string description
of the product.
*/

class UPC
{
private:
    long long code;
    string product;
public:
    UPC();
    UPC(long long code);
    UPC(long long code, string itemName);
    UPC(const UPC &other);
    UPC &operator=(const UPC &other);
    bool &operator>(const UPC &other);
    bool &operator<(const UPC &other);
    bool &operator==(const UPC &other);
    long long getCode();
    string getDescription();
    ~UPC();
};