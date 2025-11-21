#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(){
    double n;
    cin >> n;
    double ans = tan(n*3.14/180);
    cout << fixed << setprecision(2) << ans;
    return 0;
}