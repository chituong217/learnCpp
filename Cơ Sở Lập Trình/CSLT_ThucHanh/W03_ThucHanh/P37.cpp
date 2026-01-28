#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(){
    int n;
    cin >> n;
    if (n >= 1656) {
        cout << fixed << setprecision(2) << 1.00;
        return 0;
    }
    // double sum = pow(2, 1.0/2); 
    double sum = exp(log(2)/2); 
    for (int i=2; i<=n; i++){
        if (i != 2){
            // sum = pow(i + sum, 1.0/i);
            sum = exp( log(i+sum) / i);
        }
    }
    cout << fixed << setprecision(2) << sum;
    return 0;
}