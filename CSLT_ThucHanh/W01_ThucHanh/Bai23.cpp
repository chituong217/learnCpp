#include <iostream>
#include <cmath>
#include <iomanip>
#define pi 3.14
using namespace std;

int main(){
    double edge, radius;
    cin >> edge >> radius;
    double area = 3*(pow(edge,2) * sqrt(3)/ 4) + (pi * pow(radius, 2)/2);
    cout << fixed << setprecision(2) << area;
    return 0;
}