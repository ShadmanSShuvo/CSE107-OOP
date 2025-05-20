#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
class strtype
{
    char *p;

public:
    strtype(const char *s)
    {
        int l;
        l = strlen(s) + 1;
        p = new char[l];
        if (!p)
        {
            cout << "Allocation error\n";
            exit(1);
        }
        strcpy(p, s);
    }
    ~strtype() { delete[] p; }
    char *get() { return p; }
};

void show(strtype x)
{
    char *s;
    s = x.get();
    cout << s << endl;
}
int main()
{
    strtype a("Hello"), b("There");
    show(a);
    show(b);
    return 0;
}