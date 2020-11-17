#include <string>
using namespace std;

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