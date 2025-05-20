/*

➢A function address is obtained
by putting its name on the right
side of an assignment statement
without any parenthesis or arguments.
To assign p the address of zap(),
p = zap;

*/

#include <iostream>
using namespace std;
void space(int count)
{
    for (; count; count--)
        cout << '_';
}
void space(int count, char ch)
{
    for (; count; count--)
        cout << ch;
}

int main()
{
    void (*fp1)(int);
    void (*fp2)(int, char);
    fp1 = space;
    fp2 = space;
    fp1(10);
    cout << endl;
    fp2(10, 'x');
    cout << endl;
    return 0;
}