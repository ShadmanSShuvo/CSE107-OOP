#include <iostream>
using namespace std;

void f(int &p)
{
    p = 100;
}

int main()
{
    int a = 10;
    f(a);
    cout << "a: " << a << endl;
    return 0;
}