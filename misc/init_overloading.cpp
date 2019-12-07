#include <iostream>

class Point {

public:
    double x = 0;
    double y = 0;

    Point() {}
    Point(double a, double b) :
        x(a),
        y(b)
    { }
    
    // Overload + operator 
    Point operator+(const Point& rhs) const;
    Point& operator+=(const Point& rhs);
    
    void print() {
        std::cout << "(" << x << ", " << y << ")\n";
    }
};

Point Point::operator+(const Point& rhs) const {
    return Point(x + rhs.x, y + rhs.y);
}

Point& Point::operator+=(const Point& rhs) {
    x += rhs.x;
    y += rhs.y;
    return *this;
}

int main(int argc, char const *argv[])
{
    Point A(1, 0);
    Point B(0, 1.5);
    Point C = A + B;
    C.print();
    
    A += C;
    A.print();
    
    return 0;
}