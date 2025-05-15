#include <iostream>
using namespace std;
class Samp
{
    int a, b;

public:
    Samp(int n, int m)
    {
        a = n;
        b = m;
    }
    int divisible() { return !(a % b); }
};

int main()
{
    Samp s1(10, 2), s2(10, 3);
    if (s1.divisible())
        if (s2.divisible())
            cout << "10 is divisible by 2" << endl;
    cout << "10 is divisible by 3" << endl;
    return 0;
}