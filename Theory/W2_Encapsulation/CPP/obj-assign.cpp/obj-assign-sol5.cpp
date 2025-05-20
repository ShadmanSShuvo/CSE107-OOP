/*
RULE OF FIVE
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
    ObAssign(const char *s)
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

    // Copy Assignment
    ObAssign &operator=(const ObAssign &obj)
    {
        if (this == &obj)
            return *this;
        free(str);
        len = obj.len;
        str = (char *)malloc(len + 1);
        strcpy(str, obj.str);
        return *this;
    }

    // Move Constructor
    ObAssign(ObAssign &&obj) noexcept
    {
        str = obj.str;
        len = obj.len;
        obj.str = nullptr;
        obj.len = 0;
    }

    // Move Assignment
    ObAssign &operator=(ObAssign &&obj) noexcept
    {
        if (this == &obj)
            return *this;
        free(str);
        str = obj.str;
        len = obj.len;
        obj.str = nullptr;
        obj.len = 0;
        return *this;
    }

    // Destructor
    ~ObAssign()
    {
        cout << "Freeing memory" << endl;
        free(str);
    }

    void show() const
    {
        cout << str << ":" << len << endl;
    }
};

int main()
{
    ObAssign ob1("Hello World");
    ObAssign ob2 = std::move(ob1); // Move constructor
    ob2.show();

    ObAssign ob3("Temp");
    ob3 = std::move(ob2); // Move assignment
    ob3.show();

    return 0;
}