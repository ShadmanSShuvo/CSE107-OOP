/*
RULE OF THREE
*/

#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

class ObAssign
{
    char *str;
    int len;

public:
    // Constructor
    ObAssign(char *s)
    {
        len = strlen(s);
        str = (char *)malloc(len + 1);
        strcpy(str, s);
    }

    // Copy Constructor
    ObAssign(const ObAssign &obj)
    {
        len = obj.len;
        str = (char *)malloc(len + 1);
        strcpy(str, obj.str);
    }

    // Copy Assignment Operator
    ObAssign& operator=(const ObAssign &obj)
    {
        if (this == &obj)
            return *this; // Self-assignment check

        free(str);  // Free existing memory
        len = obj.len;
        str = (char *)malloc(len + 1);
        strcpy(str, obj.str);
        return *this;
    }

    // Destructor
    ~ObAssign()
    {
        cout << "Freeing memory" << endl;
        free(str);
    }

    void show()
    {
        cout << str << ":" << len << endl;
    }
};


int main()
{
    ObAssign ob1("Hello World");
    ObAssign ob2 = ob1; // Copy constructor is called
    ob2.show();

    ObAssign ob3("Temporary");
    ob3 = ob1;           // Assignment operator is called
    ob3.show();

    return 0;
}