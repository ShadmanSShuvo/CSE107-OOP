#include <iostream>
using namespace std;
class Figure
{
    double dim1, dim2;
    Figure(double a, double b)
    {
        dim1 = a;
        dim2 = b;
    }
    virtual double area() = 0; // Pure virtual function
    virtual void show() { cout << "Abstract"; }
};
 class Rectangle : public Figure
{
    Rectangle(double a, double b) { super(a, b);} 
    double area() { return dim1 * dim2; }
    void show(){cout << "Rectangle Area: " << area();
    };
     
class Triangle : public Figure
    {
        Triangle(double a, double b) { super(a, b); }
        double area() { return 0.5 * dim1 * dim2; }
        void show()
        {
            cout << ”\nTriangle Area: ” << area());
        }
    };

int main()
    {
        Rectangle r(4, 5);
        Triangle t(4, 3);
        Figure *figref;
        figref = r;
        figref.show();
        figref = t;
        figref.show();
        return 0;
    }