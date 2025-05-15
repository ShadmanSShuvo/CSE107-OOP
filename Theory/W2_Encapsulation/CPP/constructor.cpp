#include <iostream>
using namespace std;
class MyClass
{
    int a = 0;

public:
    MyClass() { cout << "No Argument Constructor" << endl; }
    MyClass(int newA); // constructor
    void show();
};

MyClass::MyClass(int newA)
{
    cout << "Constructor with Argument" << endl;
    a = newA;
}

void MyClass::show()
{
    cout << a << '\n';
}

int main()
{
    MyClass ob1, ob2(10);
    ob1.show();
    ob2.show();
    return 0;
}