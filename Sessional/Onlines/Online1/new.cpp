#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Point
{
private:
    double x;
    double y;

public:
    Point()
    {
        x = 0;
        y = 0;
    }

    Point(double X, double Y)
    {
        x = X;
        y = Y;
    }

    void setCoordinates(double X, double Y)
    {
        x = X;
        y = Y;
    }

    double getX() const { return x; }
    double getY() const { return y; }

    Point translate(double dx, double dy)
    {
        return Point(x + dx, y + dy); // Return a new translated point
    }

    double cross(const Point &other)
    {
        return x * other.y - y * other.x;
    }

    double getDistance(const Point &other)
    {
        return sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y));
    }

    void display() const
    {
        cout << "(" << x << "," << y << ")" << endl;
    }
};

class Polygon
{
private:
    Point *vertices;
    int numVertices;

public:
    Polygon() : vertices(new Point[10]), numVertices(0) {}

    Polygon(Point *inputVertices, int n)
    {
        numVertices = n;
        vertices = new Point[numVertices];
        for (int i = 0; i < numVertices; i++)
        {
            vertices[i] = inputVertices[i];
        }
    }

    Polygon(const Polygon &obj)
    {
        numVertices = obj.numVertices;
        vertices = new Point[numVertices];
        for (int i = 0; i < numVertices; i++)
        {
            vertices[i] = obj.vertices[i];
        }
    }

    Polygon& operator=(const Polygon &obj)
    {
        if (this != &obj) // Self-assignment check
        {
            delete[] vertices;

            numVertices = obj.numVertices;
            vertices = new Point[numVertices];
            for (int i = 0; i < numVertices; i++)
            {
                vertices[i] = obj.vertices[i];
            }
        }

        return *this;
    }

    void addVertex(const Point &p)
    {
        // Dynamic resizing logic should be here
        // For simplicity, we assume we're not adding more than 10 vertices
        if (numVertices < 10)
        {
            vertices[numVertices++] = p;
        }
        else
        {
            cout << "Vertex limit reached!" << endl;
        }
    }

    double getPerimeter() const
    {
        double peri = 0;
        for (int i = 0; i < numVertices; i++)
        {
            peri += vertices[i].getDistance(vertices[(i + 1) % numVertices]);
        }
        return peri;
    }

    double getArea() const
    {
        double area = 0;
        for (int i = 0; i < numVertices; i++)
        {
            area += vertices[i].getX() * vertices[(i + 1) % numVertices].getY();
            area -= vertices[i].getY() * vertices[(i + 1) % numVertices].getX();
        }

        return fabs(area / 2.0);
    }

    Polygon translate(double dx, double dy) const
    {
        Polygon poly2(*this);
        for (int i = 0; i < numVertices; i++)
        {
            poly2.vertices[i] = vertices[i].translate(dx, dy);
        }

        return poly2;
    }

    void display() const
    {
        cout << "Vertices: ";
        for (int i = 0; i < numVertices; i++)
        {
            vertices[i].display();
        }
        cout << "\nPerimeter: " << getPerimeter() << endl;
        cout << "Area: " << getArea() << endl;
    }

    ~Polygon()
    {
        delete[] vertices;
    }
};

int main()
{
    Point p1(0, 0);
    Point p2(4, 0);
    Point p3(4, 3);
    Point p4(0, 3);
    Point vertices[] = {p1, p2, p3};
    Polygon triangle(vertices, 3);
    Polygon translatedTriangle = triangle.translate(2, 1);

    cout << "Original Triangle:\n";
    triangle.display();
    cout << "\nTranslated Triangle:\n";
    translatedTriangle.display();

    Polygon square = triangle;
    square.addVertex(p4);

    cout << "\nSquare:\n";
    square.display();

    return 0;
}
