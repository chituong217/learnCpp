#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double sum(int n, double x){
    double sum = -1;
    double tmp = 1;
    for (int i=1; i <= n; i++){
        tmp = tmp * x * x / ((2.0 * i) * (2.0 * i - 1));
        if (i%2==1){
            sum += tmp;
        }
        else{
            sum -= tmp;
        }
        if (fabs(tmp) < 1e-15) {
            break; 
        }
    }
    return sum;
}

int main(){
    double x;
    int n;
    cin >> x;
    cin >> n;
    cout << fixed << setprecision(2) << sum(n, x);
    return 0;
}