// Default argument causes an ambiguous situation.
#include <iostream>
using namespace std;
int f(int a)
{
    return a * a;
}

int f(int a, int b = 0)
{
    return a * b;
}

int main()
{
    cout << f(10, 2);
    cout << f(10); // which f() is called?
    return 0;
}