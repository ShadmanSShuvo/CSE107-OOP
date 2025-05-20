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

    double getX(){
        return x;
    }
    double getY(){
        return y;
    }

    Point translate(double dx, double dy)
    {
        Point point2;
        point2.x = x + dx;
        point2.y = y + dy;
        return point2;
    }

    double cross(const Point &other)
    {
        double prod;
        prod = x * other.y - y * other.x;
        return prod;
    }

    double getDistance(const Point &other)
    {
        double dist;
        dist = sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y));
        return dist;
    }

    void display()
    {
        cout << "(" << x << "," << y << ")" << endl;
    }

    // Point &operator=(const Point &obj)
    // {
    // }
    ~Point()
    {

    }
};

class Polygon
{
private:
    Point *vertices;

    int numVertices = 0;

public:
    Polygon()
    {
        vertices = new Point[10];
    }
    Polygon(Point *vertices, int n)
    {
        numVertices = n;
        this->vertices = new Point[n];
        for (int i = 0; i < numVertices; i++)
        {
            this->vertices[i] = vertices[i];
        }
    }

    void addVertex(Point p)
    {
        vertices[numVertices++] = p;
    }

    double getPerimeter()
    {
        double peri = 0;
        for (int i = 0; i < numVertices; i++)
        {
            peri += vertices[i].getDistance(vertices[(i + 1) % numVertices]);
        }
        return peri;
    }
    double getArea()
    {
        double area = 0;
        for (int i = 0; i < numVertices; i++)
        {
            // area += vertices[i % 10].getX() * vertices[(i + 1) % 10].getY();
            // area -= vertices[i % 10].getY() * vertices[(i + 1) % 10].getX();
            area += vertices[i].cross(vertices[(i + 1) % numVertices]);
        }

        return area/2.0;
    }

    Polygon translate(double dx, double dy)
    {
        Polygon poly2;
        poly2.numVertices = numVertices;
        for (int i = 0; i < numVertices; i++)
        {
            poly2.vertices[i] = vertices[i].translate(dx, dy);
        }

        // Polygon poly2=*new Polygon();
        // poly2.numVertices = numVertices;
        
        // // for (int i = 0; i < numVertices; i++)
        // // {
        // //     poly2.vertices[i]=vertices[i];
        // // }
        // for (int i = 0; i < numVertices; i++)
        // {
        //     poly2.vertices[i].translate(dx, dy);
        // }


        return poly2;
    }
    void display()
    {
        cout << "Vertices: ";
        for (int i = 0; i < numVertices; i++)
        {
            vertices[i].display();
            cout << "\t";
        }
        cout << "\n";
        cout << "Perimeter: " << getPerimeter() << endl;
        cout << "Area: " << getArea() << endl;
    }
    Polygon &operator=(const Polygon &obj)
    {
        delete[] vertices;
        this->vertices = new Point[obj.numVertices];
        numVertices = obj.numVertices;
        //this = &obj;
        for (int i = 0; i < numVertices; i++)
        {
            this->vertices[i] = obj.vertices[i];
        }
        
        return *this;
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