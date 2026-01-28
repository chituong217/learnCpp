#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(){
    int a, b, c;
    cout << "Enter coefficients a, b, c = ";
    cin >> a >> b >> c;
    double delta = pow(b,2) - 4*a*c;
    if ( delta > 0 ){
        double x1 = (- b - sqrt(delta)) / (2*a);
        double x2 = (- b + sqrt(delta)) / (2*a);
        cout << "Solution 1 = " << fixed << setprecision(1) << x1 << endl;
        cout << "Solution 2 = " << fixed << setprecision(1) << x2 << endl;
    }
    else if ( delta == 0 ){
        double x = (- b ) / (2*a);
        cout << "Solution = " << fixed << setprecision(1) << x << endl;
    }
    else{
        cout << "No solution!" << endl;
    }
    return 0;
}