#include <iostream>
using namespace std;

void f(int a = 0, int b);

int main()
{
    f(10);
    f(10, 99);
}
void f(int a, int b)
{
    cout << a << " " << b << endl;
}
