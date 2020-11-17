#include "UPC.h"
using namespace std;

UPC::UPC() {
    code = 0;
    product = "";
}

UPC::UPC(const UPC &other) {
    this->code = other.code;
    this->product = other.product;
}

UPC &UPC::operator=(const UPC &other) {
    this->code = other.code;
    this->product = other.product;
    return *this;
}

UPC::UPC(long long code) {
    this->code = code;
    this->product = "";
}

UPC::UPC(long long code, string itemName) {
    this->code = code;
    this->product = itemName;
}

UPC::~UPC() {
}

long long UPC::getCode() {
    return this->code;
}

string UPC::getDescription() {
    return this->product;
}

bool &UPC::operator>(const UPC &other) {
    bool check = this->code > other.code;
    bool *pCheck = &check;
    return *pCheck;
}

bool &UPC::operator<(const UPC &other) {
    bool check = this->code < other.code;
    bool *pCheck = &check;
    return *pCheck;
}

bool &UPC::operator==(const UPC &other) {
    bool check = this->code == other.code;
    bool *pCheck = &check;
    return *pCheck;
}

