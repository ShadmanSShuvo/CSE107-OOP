#include <iostream>
using namespace std;
int main()
{
    int x;
    int &ref = x;
    x = 10;
    ref = 100;
    cout << x << ", " << ref << endl;
    return 0;
}