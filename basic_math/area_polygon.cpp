#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Point_t {
    double x;
    double y;
};

typedef struct Point_t Point;

// Function to get vector cross product
double getCrossProduct(Point a, Point b) {
    return (a.x*b.y - b.x*a.y);
}

// Function to find area of polygon given the vertices
double areaPolygon(vector<Point> pts) {

    double area_sum = 0.0;
    int num_pts = pts.size();

    for (int i = 0; i < num_pts; i++) {
        area_sum += getCrossProduct(pts[i], pts[(i+1)%num_pts]);
    }

    return abs(area_sum) / 2.0;
}

// Driver to test the above function
int main(int argc, char const *argv[])
{
    Point point_a = {
        1, 1
    };

    Point point_b = {
        -1, 1
    };

    Point point_c = {
        -1, -1
    };

    Point point_d = {
        1, -1
    };

    vector<Point> pts;
    pts.push_back(point_a);
    pts.push_back(point_b);
    pts.push_back(point_c);
    pts.push_back(point_d);
    
    double area = areaPolygon(pts);

    cout << area << endl;

    return 0;
}