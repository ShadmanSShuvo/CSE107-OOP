#include <iostream>
using namespace std;
inline int even(int x)
{
    return (x % 2 == 0);
}

int main()
{
    if (even(10))
        cout << "Even" << endl;
    return 0;
}