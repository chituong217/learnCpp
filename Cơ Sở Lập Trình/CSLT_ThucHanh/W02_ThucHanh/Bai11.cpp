#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int min = 1e9;
    min = fmin(a, min);
    min = fmin(b, min);
    min = fmin(c, min);
    min = fmin(d, min);
    cout << "min =" << min;
    return 0;
}