#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int n;
    cin >> n;
    double sum = 1.0/(1+1);
    for (int i=2; i<=n; i++){
        sum = 1.0/(1.0+sum);
    } 
    sum += 1.0;
    cout << fixed << setprecision(2) << sum;
    return 0;
}