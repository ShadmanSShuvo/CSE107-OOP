#include <iostream>
using namespace std;

class myclass
{
    int a;

public:
    myclass();
    ~myclass() { cout << "Destructing……\n"; };
    void show() { cout << a << endl; };
};
myclass::myclass()
{
    cout << "In constructor\n";
    a = 10;
} 
int main()
{
    myclass ob;
    ob.show();
    return 0;
};
// Destructor is called automatically when the object goes out of scope.
// This is a simple example of how constructors and destructors work in C++.
// In this example, the constructor initializes the value of 'a' to 10,
// and the destructor prints a message when the object is destroyed.
// The 'show' function prints the value of 'a'.