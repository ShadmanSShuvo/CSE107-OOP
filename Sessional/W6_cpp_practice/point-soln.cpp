#include <iostream>
using namespace std;

class Point
{
public:
    double x, y;

    Point(double x = 0, double y = 0) : x(x), y(y) {}

    // Overload + operator to add two points
    Point operator+(const Point& other) const {
        return Point(x + other.x, y + other.y);
    }

    // Overload - operator to subtract two points
    Point operator-(const Point& other) const {
        return Point(x - other.x, y - other.y);
    }

    // Overload << operator for printing a point
    friend ostream& operator<<(ostream& os, const Point& p) {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }
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
    Vector operator+(const Vector& other) const {
        return Vector(points[0] + other.points[0], points[1] + other.points[1]);
    }

    // Overload - operator to subtract two vectors (point-wise)
    Vector operator-(const Vector& other) const {
        return Vector(points[0] - other.points[0], points[1] - other.points[1]);
    }

    // Overload * operator for scalar multiplication (Vector * scalar)
    Vector operator*(double scalar) const {
        return Vector(Point(points[0].x * scalar, points[0].y * scalar),
                      Point(points[1].x * scalar, points[1].y * scalar));
    }

    // Overload * operator for scalar multiplication (scalar * Vector)
    friend Vector operator*(double scalar, const Vector& v) {
        return v * scalar;
    }

    // Overload subscript operator for const access
    const Point& operator[](int index) const {
        if (index < 0 || index > 1) {
            throw out_of_range("Vector index out of bounds");
        }
        return points[index];
    }

    // Overload << operator for printing a vector
    friend ostream& operator<<(ostream& os, const Vector& v) {
        os << "[" << v.points[0] << ", " << v.points[1] << "]";
        return os;
    }
};

int main()
{
    Point p1(1, 2), p2(3, 4);
    Point p3(5, 6), p4(7, 8);

    Vector v1(p1, p2);
    Vector v2(p3, p4);

    cout << "v1: " << v1 << endl;

    cout << "Start point v1[0]: " << v1[0] << endl;
    cout << "End point v1[1]: " << v1[1] << endl << endl;

    cout << "v2: " << v2 << endl;

    cout << "Start point v2[0]: " << v2[0] << endl;
    cout << "End point v2[1]: " << v2[1] << endl << endl;

    cout << "v1 + v2 = " << (v1 + v2) << endl;

    cout << "v1 - v2 = " << (v1 - v2) << endl;

    cout << "v1 * 2 = " << (v1 * 2) << endl;

    cout << "10 * v2 = " << (10 * v2) << endl;

    return 0;
}