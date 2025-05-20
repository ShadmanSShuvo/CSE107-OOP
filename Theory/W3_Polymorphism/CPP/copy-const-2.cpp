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
        strcpy(p, s);
        cout << "Constructing normally\n";
    }
    strtype(const strtype &s);
    ~strtype() { delete[] p; }
    char *get() { return p; }
};

strtype::strtype(const strtype &s)
{
    int l;
    l = strlen(s.p) + 1;
    p = new char[l];
    strcpy(p, s.p);
    cout << "Constructing copy\n";
}
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