#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

class ObAssign
{
    char *str;
    int len;

public:
    ObAssign(char *s)
    {
        len = strlen(s);
        str = (char *)malloc(len + 1);
        strcpy(str, s);
    }
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
    ObAssign ob1("Hello World"), ob2("like C++");
    ob1.show();
    ob2.show();
    ob2 = ob1; // This will cause a problem
    ob2.show();
}