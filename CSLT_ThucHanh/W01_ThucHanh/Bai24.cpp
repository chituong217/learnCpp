#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(){
    double percent, quota;
    cin >> percent >> quota;
    double money = (quota * 100) / percent;
    cout << fixed << setprecision(2) << money;
    return 0;
}