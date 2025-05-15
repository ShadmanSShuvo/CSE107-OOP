/*
➢Very useful for overloading certain types of
operator.


➢Allow a function to be used on the left side of an
assignment statement

#include <iostream>
using namespace std;
int x;
int &f(){
return x;
}


int main(){
f() = 100;
cout << x << endl;
return 0;
}

BUT
int &f(){
int x;
return x;
}
*/

#include <iostream>
using namespace std;
class Coord
{
    int x, y;

public:
    Coord(int a, int b)
    {
        x = a;
        y = b;
    }
    Coord &operator++()
    {
        x++;
        y++;
        return *this;
    }
    void show()
    {
        cout << "(" << x << "," << y << ")" << endl;
    }
};

int main()
{
    Coord P(10, 20);
    P.show();
    ++P;
    P.show();
    return 0;
}