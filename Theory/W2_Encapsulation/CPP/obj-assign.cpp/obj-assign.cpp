#include <iostream>
using namespace std;
class MyClass{
int a, b;
public:
void setValue(int n, int m){a = n; b = m;}
void show(){
cout << a << ", " << b << endl;
}
};

class YourClass{
    int a, b;
    public:
    void setValue(int n, int m){a = n; b = m;}
    void show(){
    cout << a << ", " << b << endl;
    }
};

int main(){
    MyClass ob1, ob2;
    YourClass ob3;
    ob1.setValue(10, 20);
    ob2 = ob1; //Ok
    // ob3 = ob1; //Compilation Error
    ob1.show();
    ob2.show();

    return 0;
}
// This code demonstrates the assignment of objects in C++.
// The class MyClass has a method to set values and show them.
// The class YourClass has similar methods.
// In the main function, an object of MyClass is assigned