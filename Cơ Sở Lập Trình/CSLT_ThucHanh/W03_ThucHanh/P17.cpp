#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    double x;
    cin >> x;
    int n;
    cin >> n;
    double pow = 1, gt = 1, sum = 0;
    for (int i=1; i<=n; i++){
        pow *= x;
        gt *= i;
        sum += pow/gt;
    }
    cout << fixed << setprecision(2) << sum;
    return 0;
}