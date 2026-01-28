#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int n;
    cin >> n;
    double sum = 0;
    for (int i=0; i<=n; i++){
        sum += 1.0/(2*i+1);
    }
    cout << fixed << setprecision(2) << sum;
    return 0;
}