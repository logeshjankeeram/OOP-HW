#include <iostream>
#include <vector>
using namespace std;

class Point {
private:
    double x, y;
public:
    Point() : x(0), y(0) {
        cout << "Default coordinates created" << endl;
    }
    Point(double x, double y) : x(x), y(y) {
        cout << "The coordinates created" << endl;
    }
    string toString() {
        return "(" + to_string(x) + ", " + to_string(y) + ")";
    }
};

class Rectangle {
private:
    double length, width;
    Point position;
public:
    Rectangle(double l, double w, double x, double y) : length(l), width(w), position(x, y) {
        cout << "Rectangle created at " << position.toString() << endl;
    }
    ~Rectangle() {
        cout << "Rectangle deleted" << endl;
    }
    double getArea() {
        return length * width;
    }
    string toString() {
        return "Rectangle: length = " + to_string(length) +
               ", width = " + to_string(width) +
               ", area = " + to_string(getArea()) +
               " and coordinates = " + position.toString();
    }
};

class Triangle {
public:
    double base, height;
    Point position;

    ~Triangle() {
        cout << "Triangle deleted" << endl;
    }
    double getArea() {
        return (base * height) / 2;
    }
    string toString() {
        return "Triangle: base = " + to_string(base) +
               ", height = " + to_string(height) +
               ", area = " + to_string(getArea()) +
               " and coordinates = " + position.toString();
    }
};

int main() {
    vector<Rectangle> rectangles;
    vector<Triangle> triangles;

    int numRectangles;
    cout << "Enter the number of rectangles: ";
    cin >> numRectangles;

    for (int i = 0; i < numRectangles; ++i) {
        double length, width, x, y;
        cout << "Enter the length of the rectangle " << i + 1 << ": ";
        cin >> length;
        cout << "Enter the width of the rectangle " << i + 1 << ": ";
        cin >> width;
        cout << "Enter the x coordinate for rectangle " << i + 1 << ": ";
        cin >> x;
        cout << "Enter the y coordinate for rectangle " << i + 1 << ": ";
        cin >> y;
        rectangles.push_back(Rectangle(length, width, x, y));
    }

    int numTriangles;
    cout << "Enter the number of triangles: ";
    cin >> numTriangles;

    for (int i = 0; i < numTriangles; ++i) {
        double base, height, x, y;
        cout << "Enter base for triangle " << i + 1 << ": ";
        cin >> base;
        cout << "Enter height for triangle " << i + 1 << ": ";
        cin >> height;
        cout << "Enter the x coordinate for triangle " << i + 1 << ": ";
        cin >> x;
        cout << "Enter the y coordinate for triangle " << i + 1 << ": ";
        cin >> y;

        Triangle trig;
        trig.base = base;
        trig.height = height;
        trig.position = Point(x, y); 
        triangles.push_back(trig);
    }

    cout << "All rectangles:" << endl;
    for (size_t i = 0; i < rectangles.size(); ++i) {
        cout << rectangles[i].toString() << endl;
    }

    cout << "All triangles:" << endl;
    for (size_t j = 0; j < triangles.size(); ++j) {
        cout << triangles[j].toString() << endl;
    }

    return 0;
}