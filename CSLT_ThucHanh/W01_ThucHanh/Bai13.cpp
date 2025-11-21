#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(){
    double edge1, edge2, edge3;
    cin >> edge1 >> edge2 >> edge3;
    double c = edge1 + edge2 + edge3;
    double p = c/2;
    double S = sqrt(p * (p-edge1) * (p-edge2) * (p-edge3));
    cout << fixed << setprecision(2) << c << " "<< S;
    return 0;
}