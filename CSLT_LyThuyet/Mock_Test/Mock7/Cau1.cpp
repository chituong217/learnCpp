#include <iostream>

using namespace std;

int digitalRoot(int n){
    if (n < 0) return -1;
    if (n < 10) return n;
    
    int tong = 0;
    while(n){
        tong += n%10;
        n/=10;
    }
    
    return digitalRoot(tong);
}