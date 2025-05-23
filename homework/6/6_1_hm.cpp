#include <iostream>
using namespace std;


class Counter {
public:
    static int count;
};
int Counter::count = 0;

template <class T1, class T2, class U = T2>
class Rectangle : public Counter {
private:
    T1 length;
    T2 width;
    U area;

public:
    Rectangle(T1 l, T2 w) : length(l), width(w) {
        area = calcArea();
        Counter::count++; 
    }
    
    U calcArea() {
        return static_cast<U>(length) * static_cast<U>(width);
    }
    
    void show() {
        cout << "length: " << length << ", width: " << width << ", area: " << area << endl;
    }
    
    static int totalCount() {
        return Counter::count;
    }
};

int main() {
    Rectangle<int, int> r1(3, 5);
    Rectangle<double, double> r2(3.4, 5.6);
    Rectangle<int, double> r3(3, 5.2);
    
    r1.show();
    r2.show();
    r3.show();
    
    cout << "total amount of rectangles: " << Rectangle<int, int>::totalCount() << endl;
    return 0;
}