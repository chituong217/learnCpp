#include <iostream>
#include <iomanip>
#include <cmath>
#define pi 3.14
#define e 2.71
using namespace std;

int main(){
    double x;
    cin >> x;
    double y1 = 4* (pow(x,2) + 10*x*sqrt(x) + 3*x +1);
    double y2 = (sin(pi*pow(x,2)) + sqrt(pow(x,2) +1)) / (pow(e, 2*x) + cos(pi*x/4));
    cout<< fixed<< setprecision(10) << y1 << " " << y2;
    return 0;
}