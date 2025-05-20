/*
RULE OF FIVE

No memory leaks, 
no double frees, 
no headaches.
*/



#include <iostream>
#include <string>
using namespace std;

class ObAssign
{
    string str;

public:
    ObAssign(const string& s) : str(s) {}

    void show() const
    {
        cout << str << ":" << str.length() << endl;
    }
};


int main()
{
    ObAssign ob1("Hello World");
    ObAssign ob2 = ob1;   // Deep copy via compiler
    ob2.show();

    ObAssign ob3("Another");
    ob3 = ob1;            // Copy assignment via compiler
    ob3.show();

    return 0;
}