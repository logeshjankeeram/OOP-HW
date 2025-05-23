#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Point
{
private:
    double x, y;

public:
    Point() : x(0), y(0)
    {
        cout << "Default coordinates created" << endl;
    }
    Point(double x, double y) : x(x), y(y)
    {
        cout << "The coordinates created" << endl;
    }
    string toString()
    {
        return "(" + to_string(x) + ", " + to_string(y) + ")";
    }
};

class Polygon
{
protected:
    double width, height;

public:
    void setValues(double width, double height)
    {
        this->width = width;
        this->height = height;
    }
};

class Rectangle : public Polygon
{
private:
    Point position;

public:
    Rectangle(double width, double height, double x, double y) : position(x, y)
    {
        setValues(width, height);
        cout << "Rectangle created at " << position.toString() << endl;
    }
    ~Rectangle()
    {
        cout << "Rectangle deleted" << endl;
    }
    double getArea()
    {
        return width * height;
    }
    string toString()
    {
        return "Rectangle: height = " + to_string(height) +
               ", width = " + to_string(width) +
               ", area = " + to_string(getArea()) +
               " and coordinates = " + position.toString();
    }
};

class Triangle : public Polygon
{
public:
    Point position;

    ~Triangle()
    {
        cout << "Triangle deleted" << endl;
    }
    double getArea()
    {
        return (width * height) / 2;
    }
    string toString()
    {
        return "Triangle: width = " + to_string(width) +
               ", height = " + to_string(height) +
               ", area = " + to_string(getArea()) +
               " and coordinates = " + position.toString();
    }
};

int main()
{
    vector<Rectangle> rectangles;
    vector<Triangle> triangles;

    int numRectangles;
    cout << "Enter the number of rectangles: ";
    cin >> numRectangles;

    for (int i = 0; i < numRectangles; ++i)
    {
        double height, width, x, y;
        cout << "Enter the height of the rectangle " << i + 1 << ": ";
        cin >> height;
        cout << "Enter the width of the rectangle " << i + 1 << ": ";
        cin >> width;
        cout << "Enter the x coordinate for rectangle " << i + 1 << ": ";
        cin >> x;
        cout << "Enter the y coordinate for rectangle " << i + 1 << ": ";
        cin >> y;
        rectangles.push_back(Rectangle(width, height, x, y));
    }

    int numTriangles;
    cout << "Enter the number of triangles: ";
    cin >> numTriangles;

    for (int i = 0; i < numTriangles; ++i)
    {
        double width, height, x, y;
        cout << "Enter the width for triangle " << i + 1 << ": ";
        cin >> width;
        cout << "Enter the height for triangle " << i + 1 << ": ";
        cin >> height;
        cout << "Enter the x coordinate for triangle " << i + 1 << ": ";
        cin >> x;
        cout << "Enter the y coordinate for triangle " << i + 1 << ": ";
        cin >> y;

        Triangle tri;
        tri.setValues(width, height);
        tri.position = Point(x, y);
        triangles.push_back(tri);
    }

    cout << "All rectangles:" << endl;
    for (size_t i = 0; i < rectangles.size(); ++i)
    {
        cout << rectangles[i].toString() << endl;
    }

    cout << "All triangles:" << endl;
    for (size_t j = 0; j < triangles.size(); ++j)
    {
        cout << triangles[j].toString() << endl;
    }

    return 0;
}