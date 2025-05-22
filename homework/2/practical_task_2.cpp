#include <iostream>
#include <vector>
using namespace std;

class Rectangle{
    private:
        double length, width;
    public:
    Rectangle(double l, double w) : length(l), width(w) {
        cout << "Rectangle created" << endl;
    }
    ~Rectangle() {
        cout << "Rectangle deleted" << endl;
    }
    double getArea() {
        return length*width;
    }
   string toString () {
        return "Rectangle: length = " + to_string(length) + " width = " + to_string(width) + " and area = " + to_string(getArea());
   }
};

class Triangle {
    public:
    double base, height;
    ~Triangle() {
        cout << "Triangle deleted" << endl;
    }
    double getArea() {
        return (base*height)/2;
    }
    string toString () {
        return "Triangle: base = " + to_string(base) + " height = " + to_string(height) + " and area = " + to_string(getArea());
    }
};

int main() {
    vector<Rectangle> rectangles;
    vector<Triangle> triangles;

    int numRectangles;
    cout << "Enter the number of rectangles - ";
    cin >> numRectangles;

    for (int i= 0; i < numRectangles; ++i) {
        double length, width;
        cout << "Enter the length of the rectangle " << i + 1 << "- ";
        cin >> length;
        cout << "Enter the width of the rectangle " << i + 1 << "- ";
        cin >> width;
        rectangles.push_back(Rectangle(length,width));
    }

       
    int numTriangles;
    cout << "Enter the number of rectangles - ";
    cin >> numTriangles;

    for (int i= 0; i < numTriangles; ++i ) {
        double base, height;
        cout << "Enter base for triangle " << i + 1 << "- ";
        cin >> base;
        cout << "Enter height for triangle " << i + 1 << "- ";
        cin >> height;
        Triangle trig;
        trig.base = base;
        trig.height = height;
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