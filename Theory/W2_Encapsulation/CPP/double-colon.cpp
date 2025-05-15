#include <iostream>
using namespace std;

class A
{
    int a;

public:
    
    void show();
    void show(int x);
    
};

void A::show()
{
    cout << "Class A" << endl;
}

void A::show(int x)
{
    cout << "Class A with " << x << endl;
}

class B
{
    int b;

public:
    void show(int x)
    {
        cout << "Class B with int: " << x << endl;
    }

    void show(double y)
    {
        cout << "Class B with double: " << y << endl;
    }

    void show()
    {
        cout << "Class B" << endl;
    }
};

class C
{
    int c;

public:
    void show(int x)
    {
        cout << "Class C with int: " << x << endl;
    }

    void show(double y)
    {
        cout << "Class C with double: " << y << endl;
    }

    void show()
    {
        cout << "Class C" << endl;
    }
};

int main()
{
    A a;
    B b;
    C c;
    a.show();
    b.show();
    c.show();
    a.show(10);
    b.show(20);
    c.show(30);
    return 0;
}