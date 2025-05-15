// ➢Wrong type of arguments causes an ambiguous situation.

#include <iostream>
using namespace std;
void f(unsigned char c)
{
    cout << c;
}
void f(char c)
{
    cout << c;
}
int main()
{
    f('c');
    f(86);
    return 0;
}
