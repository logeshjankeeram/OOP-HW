#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Shape
{
public:
    virtual double area() const = 0;
    virtual string name() const = 0;
    virtual ~Shape() = default;
};

class Triangle : public Shape
{
private:
    double base, height;

public:
    Triangle(double b, double h) : base(b), height(h) {}
    double area() const override
    {
        return 0.5 * base * height;
    }
    string name() const override
    {
        return "triangle";
    }
    Triangle operator+(const Triangle &other) const
    {
        return Triangle(base + other.base, height + other.height);
    }
};

class Circle : public Shape
{
private:
    double radius;

public:
    Circle(double r) : radius(r) {}
    double area() const override
    {
        return M_PI * radius * radius;
    }
    string name() const override
    {
        return "circle";
    }
    Circle operator+(const Circle &other) const
    {
        return Circle(radius + other.radius);
    }
};

class Rectangle : public Shape
{
private:
    double width, height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double area() const override
    {
        return width * height;
    }
    string name() const override
    {
        return "rectangle";
    }
    Rectangle operator+(const Rectangle &other) const
    {
        return Rectangle(width + other.width, height + other.height);
    }

    void newSquare(double w, double h)
    {
        width = w;
        height = h;
    }

    void newSquare(double side)
    {
        width = height = side;
    }
};

int main()
{
    vector<shared_ptr<Shape>> shapes = {
        make_shared<Triangle>(1, 2),
        make_shared<Circle>(3),
        make_shared<Rectangle>(4, 5)};

    double totalArea = 0;
    for (const auto &shape : shapes)
    {
        double area = shape->area();
        cout << "area of " << shape->name() << ": " << area << endl;
        totalArea += area;
    }

    cout << "total area of all shapes: " << totalArea << endl;

    Rectangle r1(4, 5);
    Rectangle r2(2, 3);
    Rectangle r3 = r1 + r2;
    cout << "area of combined Rectangle: " << r3.area() << endl;

    Circle c1(3);
    Circle c2(2);
    Circle c3 = c1 + c2;
    cout << "area of combined Circle: " << c3.area() << endl;

    Triangle t1(1, 2);
    Triangle t2(2, 3);
    Triangle t3 = t1 + t2;
    cout << "area of combined Triangle: " << t3.area() << endl;

    Rectangle square(0, 0);
    square.newSquare(5);
    cout << "area of square: " << square.area() << endl;

    return 0;
}

//  use g++ -std=c++11 task_5.cpp -o task_5 && ./task_5 in case of errors due to the c++11 extension
