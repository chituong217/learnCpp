#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double sum(int n, double x){
    double sum = x;
    double tmp = x;
    for (int i=1; i <= n; i++){
        tmp = tmp*x*x;
        if (i%2==0){
            sum += tmp;
        }
        else{
            sum -= tmp;
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