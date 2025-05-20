// Call by value and call by reference cause an ambiguous situation.
#include <iostream>
using namespace std;
int f(int a, int b)
{
    return a + b;
}

int f(int a, int &b)
{
    return a - b;
}

int main()
{
    int x = 1, y = 2;
    cout << f(x, y); // which f() is called?
    return 0;
}