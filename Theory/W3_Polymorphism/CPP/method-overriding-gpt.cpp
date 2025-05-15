#include <iostream>
using namespace std;

class Figure {
protected:
    double dim1, dim2;
    Figure(double a, double b) {
        dim1 = a;
        dim2 = b;
    }
public:
    virtual double area() = 0; // Pure virtual function
    virtual void show() { cout << "Abstract"; }
};

class Rectangle : public Figure {
public:
    Rectangle(double a, double b) : Figure(a, b) {}
    double area() override { return dim1 * dim2; }
    void show() override { cout << "Rectangle Area: " << area() << endl; }
};

class Triangle : public Figure {
public:
    Triangle(double a, double b) : Figure(a, b) {}
    double area() override { return 0.5 * dim1 * dim2; }
    void show() override { cout << "Triangle Area: " << area() << endl; }
};

int main() {
    Rectangle r(4, 5);
    Triangle t(4, 3);
    Figure* figref;

    figref = &r;
    figref->show();

    figref = &t;
    figref->show();

    return 0;
}