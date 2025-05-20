#include <iostream>
using namespace std;
class Samp
{
    int a, b;

public:
    Samp()
    {
        a = 0;
        b = 0;
    }
    Samp(int x, int y)
    {
        a = x;
        b = y;
    }
    int getProduct() { return a * b; }
};

int main()
{
    Samp *p = new Samp;
    Samp *q = new Samp(3, 4);
    Samp *r = new Samp[2];
    cout << "Product: " << p->getProduct() << endl;
    cout << "Product: " << q->getProduct() << endl;
    for (int i = 0; i < 2; i++)
    {
        r[i] = Samp(i + 1, i + 2);
        cout << r[i].getProduct() << endl;
    }
    delete p;
    delete q;
    delete[] r;
    return 0;
}