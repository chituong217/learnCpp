#include <bits/stdc++.h>

using namespace std;

class Point3D{
private:
    double x, y, z;
public:
    Point3D();
    Point3D(double x, double y, double z);
    double distance(Point3D other);
    void move(double dx, double dy, double dz);
    void rotate();
};

Point3D::Point3D(){
    x = 0; y = 0; z = 0;
}

Point3D::Point3D(double x, double y, double z){
    this->x = x;
    this->y = y;
    this->z = z;
}

double Point3D::distance(Point3D other){
    return sqrt( pow(this->x - other.x, 2) + pow(this->y - other.y, 2) + pow(this->z - other.z, 2));
}

void Point3D::move(double dx, double dy, double dz){
    x += dx;
    y += dy;
    z += dz;
}

void Point3D::rotate(){
    int tmp = x;
    x = -y;
    y = tmp;
}


#include "main.h"
// int main(){
//     return 0;
// }