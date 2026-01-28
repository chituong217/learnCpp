#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    double x;
    cin >> x;
    int n;
    cin >> n;
    double sum = 0;
    double tmp = 1;
    for (int i=1; i<=n; i++){
        tmp = tmp * x * x;
        sum += tmp;
    }
    cout << fixed << setprecision(2) << sum;
    return 0;
}