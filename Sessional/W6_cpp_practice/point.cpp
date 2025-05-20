#include <iostream>
using namespace std;

class Point
{
public:
    double x, y;

    Point(double x = 0, double y = 0) : x(x), y(y) {}

    // Overload + operator to add two points

    // Overload - operator to subtract two points

    // Overload << operator for printing a point
};

class Vector
{
private:
    Point points[2]; // exactly two points: points[0] = start, points[1] = end

public:
    // Constructors
    Vector() : points{Point(), Point()} {}

    Vector(const Point &start, const Point &end)
    {
        points[0] = start;
        points[1] = end;
    }

    // Accessors
    Point &start() { return points[0]; }
    Point &end() { return points[1]; }

    const Point &start() const { return points[0]; }
    const Point &end() const { return points[1]; }

    // Overload + operator to add two vectors (point-wise)

    // Overload - operator to subtract two vectors (point-wise)

    // Overload * operator for scalar multiplication (Vector * scalar)

    // Overload * operator for scalar multiplication (scalar * Vector)

    // Overload subscript operator for const access

    // Overload << operator for printing a vector
};

int main()
{
    Point p1(1, 2), p2(3, 4);
    Point p3(5, 6), p4(7, 8);

    Vector v1(p1, p2);
    Vector v2(p3, p4);

    cout << "v1: " << "Implement << operator for Vector to print v1" << endl;

    cout << "Start point v1[0]: " << "Implement subscript operator for Vector to access start point" << endl;
    cout << "End point v1[1]: " << "Implement subscript operator for Vector to access end point" << endl
         << endl;

    cout << "v2: " << "Implement << operator for Vector to print v2" << endl;

    cout << "Start point v2[0]: " << "Implement subscript operator for Vector to access start point" << endl;
    cout << "End point v2[1]: " << "Implement subscript operator for Vector to access end point" << endl
         << endl;

    cout << "v1 + v2 = " << "Implement + operator for Vector to add v1 and v2" << endl;

    cout << "v1 - v2 = " << "Implement - operator for Vector to subtract v1 and v2" << endl;

    cout << "v1 * 2 = " << "Implement * operator for Vector to multiply v1 by scalar" << endl;

    cout << "10 * v2 = " << "Implement * operator for Vector to multiply scalar by v2" << endl;


    return 0;
}
