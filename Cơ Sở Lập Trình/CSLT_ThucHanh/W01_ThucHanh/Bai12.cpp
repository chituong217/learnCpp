#include <iostream>
using namespace std;

int main(){
    int quantity, price;
    cin >> quantity >> price;
    long long val = quantity*price;
    int tax = val*10/100;
    long long ans = val + tax;
    cout << ans;
    return 0;
}