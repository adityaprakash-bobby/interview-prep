#include <iostream>

using namespace std;

struct Point_t {
    double x;
    double y;
};

typedef struct Point_t Point;

enum POINT_POSITION_t {
    ON_THE_LINE,
    TO_RIGHT,
    TO_LEFT
};

typedef POINT_POSITION_t POINT_POSITION;

// Subtract point 'a' from point 'b' so that all the points lie w/r/t to 'a'
// as the origin
Point subtract(Point b, Point a) {

    Point res;

    res.x = b.x - a.x;
    res.y = b.y - a.y;

    return res;

}

// Function to get the vector cross-product of two points
double getCrossProduct(Point a, Point b) {
    return (a.x*b.y - b.x*a.y);
}

// Function to determine where the point 'p' lies w/r/t to 'a' and 'b'
POINT_POSITION getDirection(Point a, Point b, Point p) {

    // Shift points w/r/t to the origin
    b = subtract(b, a);
    p = subtract(p, a);

    // determine the value of the cross product
    double cross_product = getCrossProduct(b, p);

    if (cross_product == 0) {
        return ON_THE_LINE;
    } else if (cross_product > 0) {
        return TO_LEFT;
    } else {
        return TO_RIGHT;
    }
}

// Driver to test the above function
int main(int argc, char const *argv[])
{
    Point point_a = {
        3, 4,
    };

    Point point_b = {
        5, 6
    };

    Point point_p = {
        -7, 8
    };
    
    POINT_POSITION res = getDirection(point_a, point_b, point_p);

    cout << res << endl;

    return 0;
}